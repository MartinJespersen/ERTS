#pragma once
// Inspired by: https://embeddedartistry.com/blog/2018/07/12/simple-fixed-point-conversion-in-c/
#define FIXED_FRACT_BITS 8
typedef uint16_t fixed_point_t;
typedef double convert_float_t; 

/* Fixed Point Format Using Q
* Q12.4 has 12 integer bits and 4 fractional bits
* Some bits of the register will representation whole number and
* some bits will representate the fractionsal number.
* See https://www.youtube.com/watch?v=QFlbvSeBkwY
*/
fixed_point_t float_to_fixed(convert_float_t input)
{
	return (fixed_point_t)(input * (1UL << FIXED_FRACT_BITS));
}

float fixed_to_float(fixed_point_t input)
{
	return ((convert_float_t)input / (convert_float_t)(1UL << FIXED_FRACT_BITS));
}

fixed_point_t add_int(fixed_point_t input, int val)
{
	return input += (signed long)val << FIXED_FRACT_BITS;
}

// This is not ideal since only 4 fractional bits. 
fixed_point_t add_float(fixed_point_t input, convert_float_t val)
{
	return input += float_to_fixed(val);
}

// Closest to PI using Q format
fixed_point_t get_pi_fixed()
{
	const float M_PI = 3.14159265358979323846;
	return (fixed_point_t)(M_PI * (1UL << FIXED_FRACT_BITS));
}

// Inspired by: https://en.wikipedia.org/wiki/Q_(number_format)
// precomputed value:
#define K   (1 << (FIXED_FRACT_BITS - 1))

fixed_point_t fixed_multiply(fixed_point_t a, fixed_point_t b)
{
	fixed_point_t result;
	fixed_point_t temp;

	temp = a * b; // result type is operand's type
	// Rounding; mid values are rounded up
	temp += K;
	// Correct by dividing by base and saturate result
	result = temp >> FIXED_FRACT_BITS;

	return result;
}


