#pragma once
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <limits>
#include "random_generator.h"
#define __ON_TARGET__ 
#define _m_particles 20 
#define _n_dimensions 2 
#define from -3
#define to 3 


class pos_algo
{
public:
	pos_algo(float g [_n_dimensions]);
	void pos_start(float g [_n_dimensions]);

private:
	const unsigned short int _stop;
	const float _w;
	const float _c1;
	const float _c2;

	float v[_m_particles][_n_dimensions];
	float x[_m_particles][_n_dimensions];
	float r[_m_particles][_n_dimensions];
	float s[_m_particles][_n_dimensions];
	float p[_m_particles][_n_dimensions];

	random_generator r_gen; 

	float objective_function(float [_n_dimensions]);
	void populate_matrix(float [_m_particles][_n_dimensions], const short int, const short int );
	void copy_matrix(float [_m_particles][_n_dimensions], float [_m_particles][_n_dimensions]);
	void copy_vector(float[_n_dimensions], float[_n_dimensions]);
	float uniform_random(const signed short int, const signed short int);
#ifndef __ON_TARGET__  
	void display_matrix(const std::string& matrix_name, const float[_m_particles][_n_dimensions]);
	void display_vector(const std::string& vector_name, const float[_n_dimensions]);
#endif 
};
