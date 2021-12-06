#pragma once
#include <cmath> 
#include <iostream>

// Class uses linear congruential generator.
// Inspiration from: https://www.youtube.com/watch?v=4sYawx70iP4.
class random_generator
{
public:
	// Generates a pseudo random number between [0, 1]
	random_generator();
	float nextRand();
	float nextRand(const signed short int from, const signed short int to);
private:
	int _seed;
	// Values are chosen based on used parameters: https://en.wikipedia.org/wiki/Linear_congruential_generator.
	// Using C++11 mnisk values. 
	const unsigned int _multiplier;
	const unsigned int _modulus;
};
