#include "random_generator.h"

// Values are chosen based on used parameters: https://en.wikipedia.org/wiki/Linear_congruential_generator.
// Using C++11 mnisk values. 
random_generator::random_generator() :
	_seed(1),
	_multiplier(48271),
	_increment(0),
	_modulus(pow(2, 31) - 1)
{}

// Generates a pseudo random number between [0, 1]
double random_generator::nextRand()
{
	_seed = (_multiplier * _seed + _increment) % _modulus;
	// TODO: Make fixed arithmetic? 
	double value = (double)_seed / _modulus; 
	return value;
}

double random_generator::nextRand(const int from, const int to)
{
	int offset = (std::abs(from) + std::abs(to) - std::abs(to));
	double value = offset > 0 ? (nextRand() * offset) : nextRand(); 
	return value; 
}
