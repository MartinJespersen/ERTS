#include "pos.h"


template<size_t _m_particles, size_t _n_dimensions>
pos<_m_particles, _n_dimensions>::pos(const int stop_criteria, const int _w, const int _c1, const int _c2, int from, int to) :
    _stop(stop_criteria),
    _w(_w),
    _c1(_c1),
    _c2(_c2)
{
    // Generate inital positions. 
    populate_matrix(&x[0][0], from, to);
    populate_matrix(&v[0][0], from, to);
    display_matrix("Initial Position matrix", &x[0][0]);
    display_matrix("Initial Velocity matrix", &x[0][0]);

    // Set personal best to initial positions. 
    memcpy(p, x, _m_particles * _n_dimensions * sizeof(double));
    display_matrix("Initial Personal Best Matrix", &p[0][0]);

    // Set global best based on initial personal best. 
    int index_global_best = 0;
    double temp_objective_value = 0;
    double current_best_value = std::numeric_limits<double>::max();
    for (int i = 0; i < _m_particles; i++) {
        temp_objective_value = objective_function(x[i]);
        if (temp_objective_value < current_best_value) {
            index_global_best = i;
            current_best_value = temp_objective_value;
        }
    }

    for (int i = 0; i < _n_dimensions; i++) {
        g[i] = x[index_global_best][i];
    }
    display_vector("Initial Global Best", g);

    // Start simulation.
    pos_start();
}

template<size_t _m_particles, size_t _n_dimensions>
double* pos<_m_particles, _n_dimensions>::pos_start()
{
    high_res_time start = std::chrono::high_resolution_clock::now();
    double global_objective_function_res = objective_function(g);
    double local_objective_function_res[_m_particles];
    double x_objective_function_res;

    for (int i = 0; i < _stop; i++) {
        populate_matrix(&r[0][0], 0, 1);
        populate_matrix(&s[0][0], 0, 1);
        if (i == 0) {
            for (int j = 0; j < _m_particles; j++) {
                local_objective_function_res[j] = objective_function(x[0]);
            }
        }
        for (int m = 0; m < _m_particles; m++) {
            for (int n = 0; n < _n_dimensions; n++) {
                v[m][n] = _w * v[m][n] + _c1 * r[m][n] * (p[m][n] - x[m][n]) + _c2 * s[m][n] * (g[n] - x[m][n]);
                x[m][n] = x[m][n] + v[m][n];
            }
        }

        for (int m = 0; m < _m_particles; m++) {
            x_objective_function_res = objective_function(x[m]);
            if (x_objective_function_res < local_objective_function_res[m]) {
                for (int n = 0; n < _n_dimensions; n++) {
                    p[m][n] = x[m][n];
                }
                local_objective_function_res[m] = objective_function(x[m]);

                if (x_objective_function_res < global_objective_function_res) {
                    for (int n = 0; n < _n_dimensions; n++) {
                        g[n] = x[m][n];
                    }
                    global_objective_function_res = objective_function(g);
                }
            }

            
        }
    }

    display_vector("Final Global Best", g);

    return g;
}

template<size_t _m_particles, size_t _n_dimensions>
double pos<_m_particles, _n_dimensions>::uniform_random(double from, double to)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_real_distribution<double> dist6(from, to);
    return dist6(rng);
}

template<size_t _m_particles, size_t _n_dimensions>
double pos<_m_particles, _n_dimensions>::objective_function(double* x)
{
    const double e = std::exp(1.0);
    return 3 * pow(1 - x[0], 2) * exp(pow(-x[0], 2) - pow(x[1] + 1, 2)) - 10 * (x[0] / 5 - pow(x[0], 3) - pow(x[1], 5)) * exp(-pow(x[0], 2) - pow(x[1], 2)) - (exp(-pow(x[0] + 1, 2) - pow(x[1], 2))) / 3;
}

template<size_t _m_particles, size_t _n_dimensions>
void pos<_m_particles, _n_dimensions>::populate_matrix(double* mat, double from, double to)
{
    for (int i = 0; i < _m_particles; i++) {
        for (int j = 0; j < _n_dimensions; j++) {
            (mat + (i * _n_dimensions))[j] = uniform_random(from, to);
        }
    }
}

template<size_t _m_particles, size_t _n_dimensions>
void pos<_m_particles, _n_dimensions>::display_matrix(const std::string& matrix_name, double* mat)
{
    std::cout << matrix_name << std::endl;
    for (int i = 0; i < _m_particles; i++) {
        for (int j = 0; j < _n_dimensions; j++) {
            std::cout << (mat + (i * _n_dimensions))[j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

template<size_t _m_particles, size_t _n_dimensions>
void pos<_m_particles, _n_dimensions>::display_vector(const std::string& vector_name, double* vect)
{
    std::cout << vector_name << std::endl;
    for (int i = 0; i < _n_dimensions; i++)
    {
        std::cout << vect[i] << " ";
    }
    std::cout << std::endl << std::endl;
}

// This is needed for the C++ linker. 
template class pos<20, 2>;
