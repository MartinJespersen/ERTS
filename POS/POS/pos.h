#pragma once
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <random>
#include <string>
#include <cmath>
#include <limits>

template<size_t _m_particles, size_t _n_dimensions>
class pos
{
public:
    pos(const int stop_criteria, const int _w, const int _c1, const int _c2, int from, int to);
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

    double objective_function(double* x);
    void populate_matrix(double* mat, double from, double to);
    void display_matrix(const std::string& matrix_name, double* mat);
    void display_vector(const std::string& vector_name, double* vect);
    double uniform_random(double from, double to);
    double* pos_start();
};
