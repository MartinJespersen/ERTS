#include "random_generator_fixed.h"

random_generator_fixed::random_generator_fixed() :
	_seed(1),
	_multiplier(75),
	_increment(74),
	_modulus(65537)
{}

fixed_point_t random_generator_fixed::abs(fixed_point_t input)
{
	if (input < 0)
		return -input;
	else
		return input;
}

int random_generator_fixed::abs(const int input)
{
	if (input < 0)
		return -input;
	else
		return input;
}

fixed_point_t random_generator_fixed::nextRand()
{
	_seed = (_multiplier * _seed + _increment) % _modulus;
	fixed_point_t value = (fixed_point_t)_seed / _modulus;
	return value;
}

fixed_point_t random_generator_fixed::nextRand(const signed short int f, const signed short int t)
{
	int offset = abs(f) + abs(t);
	fixed_point_t value = (nextRand() * offset) - abs(f);

	return value;
}
