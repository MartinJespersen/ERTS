#pragma once
#include "hls_fixed_point.h"

class random_generator_fixed
{
public:
	random_generator_fixed();
	fixed_point_t abs(fixed_point_t);
	int abs(const int);
	fixed_point_t nextRand();
	fixed_point_t nextRand(const signed short int, const signed short int);
private:
	din_t _seed;
	const din_t _multiplier;
	const din_t _increment;
	const din_t _modulus;
};
