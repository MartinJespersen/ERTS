#pragma once
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <random>
#include <string>
#include <cmath>

template<size_t _m_particles, size_t _n_dimensions>  
class pos
{
public:
	pos(int stop_criteria, int w, int c1, int c2);
	double pos_start(double (*func)(double *)); 
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

	void populate_position_matrix(double * mat, double from, double to);
    void display_matrix(double* mat); 
	double uniform_random(double from, double to); 
};

template<size_t _m_particles, size_t _n_dimensions>
pos<_m_particles, _n_dimensions>::pos(int stop_criteria, int w, int c1, int c2) :
    _stop(stop_criteria),
    _w(w),
    _c1(c1),
    _c2(c2)
{
    populate_position_matrix(&x[0][0], -2, 2); 
    display_matrix(&x[0][0]);
}

template<size_t _m_particles, size_t _n_dimensions>
double pos<_m_particles, _n_dimensions>::pos_start(double (*objective_f)(double *))
{
    return 0; 
}

template<size_t _m_particles, size_t _n_dimensions>
double pos<_m_particles, _n_dimensions>::uniform_random(double from, double to)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_real_distribution<double> dist6(_m_particles, _n_dimensions);
    return dist6(rng);
}

template<size_t _m_particles, size_t _n_dimensions>
void pos<_m_particles, _n_dimensions>::populate_position_matrix(double * mat, double from, double to)
{
    for(int i = 0; i < _m_particles; i++) {
        for (int j = 0; j < _n_dimensions; j++) {
            (mat + (i * _n_dimensions))[j] = uniform_random(from, to);
        }
    }
}

template<size_t _m_particles, size_t _n_dimensions>
void pos<_m_particles, _n_dimensions>::display_matrix(double * mat)
{
    for (int i = 0; i < _m_particles; i++) {
        for (int j = 0; j < _n_dimensions; j++) {
            std::cout << (mat + (i * _n_dimensions))[j] << " ";
        }
        std::cout << std::endl;
    }     
}