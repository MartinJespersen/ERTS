#pragma once
#include <stdlib.h>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <limits>
#include "random_generator_fixed.h"
#include "hls_fixed_point.h"
#define __ON_TARGET__
#define _m_particles 20		
#define _n_dimensions 2 
#define from -3 
#define to 3 

#ifdef __ON_TARGET__
#include <iostream>
#endif

class pos_algo_fixed
{
public:
	pos_algo_fixed(fixed_point_t[_n_dimensions]);
	void pos_start(fixed_point_t[_n_dimensions]);

private:
	const unsigned short int _stop;
	const fixed_point_t _w;
	const fixed_point_t _c1;
	const fixed_point_t _c2;

	fixed_point_t v[_m_particles][_n_dimensions];
	fixed_point_t x[_m_particles][_n_dimensions];
	fixed_point_t r[_m_particles][_n_dimensions];
	fixed_point_t s[_m_particles][_n_dimensions];
	fixed_point_t p[_m_particles][_n_dimensions];

	random_generator_fixed r_gen;

	fixed_point_t objective_function(fixed_point_t[_n_dimensions]);
	void populate_matrix(fixed_point_t[_m_particles][_n_dimensions], const signed short int, const signed short int);
	void copy_matrix(fixed_point_t[_m_particles][_n_dimensions], fixed_point_t[_m_particles][_n_dimensions]);
	void copy_vector(fixed_point_t[_n_dimensions], fixed_point_t[_n_dimensions]);
	fixed_point_t uniform_random(const signed short int, const signed short int);
#ifndef __ON_TARGET__  
	void display_matrix(const std::string& matrix_name, const fixed_point_t[_m_particles][_n_dimensions]);
	void display_vector(const std::string& vector_name, const fixed_point_t[_n_dimensions]);
#endif 
};
