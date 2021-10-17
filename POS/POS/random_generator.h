#pragma once
#include <cmath> 

// Class uses linear congruential generator.
// Inspiration from: https://www.youtube.com/watch?v=4sYawx70iP4.
class random_generator
{
public:
	// Generates a pseudo random number between [0, 1]
	random_generator(); 
	double nextRand();
	double nextRand(const int from, const int to);
private:
	int _seed;
	// Values are chosen based on used parameters: https://en.wikipedia.org/wiki/Linear_congruential_generator.
	// Using C++11 mnisk values. 
	const int _multiplier;
	const int _increment;
	const int _modulus;
};