#include "random_generator.h"

// Values are chosen based on used parameters: https://en.wikipedia.org/wiki/Linear_congruential_generator.
// Using C++11 mnisk values. 
random_generator::random_generator() :
	_seed(1),
	_multiplier(16807),
	_modulus(2147483647)
{}

// Generates a pseudo random number between [0, 1]
float random_generator::nextRand()
{
	_seed = (_multiplier * _seed) % _modulus;
	float value = (float)_seed / _modulus;

	return value;
}

// Generates a pseudo random number between [from, to]
float random_generator::nextRand(const signed short int f, const signed short int t)
{
	int offset = (std::abs(f) + std::abs(t) - std::abs(t));
	float value = offset > 0 ? (nextRand() * offset) : nextRand();
	if (value < f)
	{
		value = fabsf(value);
	}
	return value;
}