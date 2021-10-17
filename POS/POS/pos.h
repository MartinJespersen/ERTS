#pragma once
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <limits>
#include "random_generator.h"

template<size_t _m_particles, size_t _n_dimensions>
class pos
{
public:
    pos(const int stop_criteria, const int _w, const int _c1, const int _c2, const int from, const int to);
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

    random_generator _r_gen;

    double objective_function(double* x);
    void populate_matrix(double* mat, const int from, const int to);
    void display_matrix(const std::string& matrix_name, const double* mat);
    void display_vector(const std::string& vector_name, const double* vect);
    double uniform_random(const int from, const int to);
    double* pos_start();
};
