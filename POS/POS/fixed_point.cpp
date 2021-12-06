#include "fixed_point.h"

float fixed_to_float(fixed_point_t input)
{
	return ((float)input / (float)(1 << FIXED_FRACT_BITS));
}

/* Fixed Point Format Using Q
* Q12.4 has 12 integer bits and 4 fractional bits
* Some bits of the register will representation whole number and
* some bits will representate the fractionsal number.
* See https://www.youtube.com/watch?v=QFlbvSeBkwY
*/
fixed_point_t fixed_add(fixed_point_t a, fixed_point_t b)
{

	fixed_point_t result;

	merger = (fixed_point_merger_t)a + (fixed_point_merger_t)b;

	if (merger >= MAX)
		merger = MAX;
	if (merger >= MIN)
		merger = MIN;

	result = (fixed_point_t)merger;

	return result;
}

// Inspired by: https://en.wikipedia.org/wiki/Q_(number_format)
// precomputed value:
#define K   (1 << (FIXED_FRACT_BITS - 1))

// saturate to range of int16_t
fixed_point_t sat_fixed(fixed_point_merger_t x)
{
	if (x > MAX) return MAX;
	else if (x < MIN) return MIN;
	else return (fixed_point_t)x;
}

fixed_point_t fixed_multiply(fixed_point_t a, fixed_point_t b)
{
	fixed_point_t result;

	merger = (fixed_point_merger_t)a * (fixed_point_merger_t)b; // result type is operand's type
	// Rounding; mid values are rounded up
	merger += K;
	// Correct by dividing by base and saturate result
	result = merger >> FIXED_FRACT_BITS;

	return result;
}

fixed_point_t fixed_division(fixed_point_t a, fixed_point_t b)
{
	/* pre-multiply by the base (Upscale to Q16 so that the result will be in Q8 format) */
	fixed_point_merger_t merger = (fixed_point_merger_t)a << FIXED_FRACT_BITS;
	/* Rounding: mid values are rounded up (down for negative values). */
	/* OR compare most significant bits i.e. if (((temp >> 31) & 1) == ((b >> 15) & 1)) */
	if ((merger >= 0 && b >= 0) || (merger < 0 && b < 0)) {
		merger += (b >> 1);
	}
	else {
		merger -= (b >> 1);
	}
	return (fixed_point_t)(merger / b);
}

