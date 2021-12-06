#include "pos_algo_fixed.h"

pos_algo_fixed::pos_algo_fixed(fixed_point_t g[_n_dimensions]) :
	_stop(100),
	_w(0.8),
	_c1(1.98),
	_c2(1.95)
{
	// Generate initial positions.
	populate_matrix(x, from, to);
	populate_matrix(v, from, to);
	// Set personal best to initial positions. 
	copy_matrix(x, p);

	// Set global best based on initial personal best. 
	unsigned short int index_global_best = 0;
	fixed_point_t temp_objective_value = 0;
	fixed_point_t current_best_value = FIXED_MAX;
	for (unsigned short int i = 0; i < _m_particles; i++) {
		temp_objective_value = objective_function(x[i]);
		if (temp_objective_value < current_best_value) {
			index_global_best = i;
			current_best_value = temp_objective_value;
		}
	}

	for (unsigned short int i = 0; i < _n_dimensions; i++) {
		g[i] = x[index_global_best][i];
	}

#ifndef __ON_TARGET__
	display_matrix("Initial Position matrix", x);
	display_matrix("Initial Velocity matrix", v);
	display_matrix("Initial Personal Best Matrix", p);
	display_vector("Initial Global Best", g);
#endif
}

fixed_point_t pos_algo_fixed::uniform_random(const signed short int f, const signed short int t)
{
	return r_gen.nextRand(f, t);
}

void pos_algo_fixed::pos_start(fixed_point_t g[_n_dimensions])
{
	fixed_point_t global_objective_function_res = objective_function(g);
	fixed_point_t local_objective_function_res[_m_particles];
	fixed_point_t x_objective_function_res = 0;

	for (unsigned short int i = 0; i < _stop; i++) {
		populate_matrix(r, 0, 1);
		populate_matrix(s, 0, 1);
		if (i == 0) {
			for (unsigned short int j = 0; j < _m_particles; j++) {
				local_objective_function_res[j] = objective_function(x[i]);
			}
		}
		for (unsigned short int m = 0; m < _m_particles; m++) {
			for (unsigned short int n = 0; n < _n_dimensions; n++) {
				v[m][n] = _w * v[m][n] + (_c1 * r[m][n]) * (p[m][n] - x[m][n]) + (_c2 * s[m][n]) * (g[n] - x[m][n]);
				x[m][n] = x[m][n] + v[m][n];
			}
		}

		for (unsigned short int m = 0; m < _m_particles; m++) {
			x_objective_function_res = objective_function(x[m]);
			if (x_objective_function_res < local_objective_function_res[m]) {
				for (unsigned short int n = 0; n < _n_dimensions; n++) {
					p[m][n] = x[m][n];
				}
				local_objective_function_res[m] = objective_function(x[m]);

				if (x_objective_function_res < global_objective_function_res) {
					for (unsigned short int n = 0; n < _n_dimensions; n++) {
						g[n] = x[m][n];
					}
					global_objective_function_res = objective_function(g);
				}
			}
		}
	}

#ifndef __ON_TARGET__
	display_vector("Final Global Best", g);
#endif
}

fixed_point_t pos_algo_fixed::objective_function(fixed_point_t x[_n_dimensions])
{
	return x[0] * x[0] + x[1] * x[1];
}


void pos_algo_fixed::populate_matrix(fixed_point_t mat[_m_particles][_n_dimensions], const signed short int f, const signed short int t)
{
	for (unsigned short int i = 0; i < _m_particles; i++) {
		for (unsigned short int j = 0; j < _n_dimensions; j++) {
			mat[i][j] = uniform_random(f, t);
		}
	}
}

void pos_algo_fixed::copy_matrix(fixed_point_t copy_from[_m_particles][_n_dimensions], fixed_point_t copy_to[_m_particles][_n_dimensions])
{
	for (unsigned short int i = 0; i < _m_particles; i++) {
		for (unsigned short int j = 0; j < _n_dimensions; j++) {
			copy_to[i][j] = copy_from[i][j];
		}
	}
}


void pos_algo_fixed::copy_vector(fixed_point_t copy_from[_n_dimensions], fixed_point_t copy_to[_n_dimensions])
{
	for (unsigned short int i = 0; i < _n_dimensions; i++) {
		copy_to[i] = copy_from[i];
	}
}

#ifndef __ON_TARGET__
void pos_algo_fixed::display_matrix(const std::string& matrix_name, const fixed_point_t mat[_m_particles][_n_dimensions])
{
	std::cout << matrix_name << std::endl;
	for (unsigned short int i = 0; i < _m_particles; i++) {
		for (unsigned short int j = 0; j < _n_dimensions; j++) {
			std::cout << mat[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void pos_algo_fixed::display_vector(const std::string& vector_name, const fixed_point_t vect[_n_dimensions])
{
	std::cout << vector_name << std::endl;
	for (unsigned short int i = 0; i < _n_dimensions; i++)
	{
		std::cout << vect[i] << " ";
	}
	std::cout << std::endl << std::endl;
}
#endif
