#pragma once
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <random>
#include <string>
#include <cmath>
#include <limits.h>
#include <chrono>

typedef std::chrono::time_point<std::chrono::high_resolution_clock> high_res_time;

template<size_t _m_particles, size_t _n_dimensions>
class partical_swarm_debug_data
{
public:
    double v[_m_particles][_n_dimensions];
    double x[_m_particles][_n_dimensions];
    double g[_n_dimensions];
    double r[_m_particles][_n_dimensions];
    double s[_m_particles][_n_dimensions];
    double p[_m_particles][_n_dimensions];
};

template<size_t _m_particles, size_t _n_dimensions>  
class pos
{
public:
	pos(double (*objective_function)(double*), int stop_criteria, int _w, int _c1, int _c2, int from, int to);
	double * pos_start(); 
private:
	const int _stop; 
	const int _w; 
	const int _c1; 
	const int _c2; 

    double v[_m_particles][_n_dimensions];
    double x[_m_particles][_n_dimensions];
    double g[_n_dimensions];
	double r[_m_particles][_n_dimensions];
    double s[_m_particles][_n_dimensions];
    double p[_m_particles][_n_dimensions];

    double (*_objective_function)(double*);

	void populate_matrix(double * mat, double from, double to);
    void display_matrix(const std::string& matrix_name, double* mat);
    void display_vector(const std::string& vector_name, double* vect);
    double uniform_random(double from, double to); 
};
