#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <random>
#include <string>
#include <cmath>
#include "pos.h"

double uniform_random(double m, double n)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_real_distribution<double> dist6(m, n);
    return dist6(rng);
}

void populate_matrix(double * mat, int m, int n, int from, int to) {
    for(int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            (mat + (i * n))[j] = uniform_random(from, to);
        }
}

void display_matrix(double * mat, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << (mat + (i * n))[j] << " ";
        }
        std::cout << std::endl;
    }        
}

double objective_function(double * x) {
    const double e = std::exp(1.0);
    return 3*pow(1 - x[0], 2) * exp(pow(-x[0], 2) - pow(x[1] + 1, 2)) - 10 * (x[0] / 5 - pow(x[0], 3) - pow(x[1], 5)) * exp(-pow(x[0], 2) - pow(x[1], 2)) - (exp(-pow(x[0] + 1, 2) - pow(x[1], 2))) / 3;
}

int main()
{
    std::random_device dev;
    std::mt19937 rng(dev());
    
    const int m_particles = 20;
    const int n_dimensions = 2;
    const int stopping_criteria = 100;
    const int from = -3.;
    const int to = 3.;
    const double w = 0.8;
    const double c1 = 1.95;
    const double c2 = 1.98;

    pos<m_particles, n_dimensions> pos_obj(objective_function, stopping_criteria, w, c1, c2, from, to);
	double * g_final_vect = pos_obj.pos_start(); 

	
	// Rows represent particles 
	// Columns represent particle position or velocity
	// i.e. x[0][0] will return the position of particle 0. 
	//double v[m_particles][n_dimensions];
	//double x[m_particles][n_dimensions];
	//double g[n_dimensions];
	//double r[m_particles][n_dimensions];
	//double s[m_particles][n_dimensions];

	//populate_matrix(&x[0][0], m_particles, n_dimensions, from, to);
	//display_matrix(&x[0][0], m_particles, n_dimensions);
	//std::cout << std::endl;
	//populate_matrix(&v[0][0], m_particles, n_dimensions, from, to);
	//double p[m_particles][n_dimensions];
	//memcpy(p, x, m_particles * n_dimensions * sizeof(double));
	//std::cout << std::endl;
	//display_matrix(&p[0][0], m_particles, n_dimensions);
	//std::cout << std::endl;
	//display_matrix(&v[0][0], m_particles, n_dimensions);

	//for (int j = 0; j < n_dimensions; j++) {
	//	g[j] = x[0][j];
	//}

	//for (int i = 0; i < m_particles; i++) {
	//	if (objective_function(x[i]) < objective_function(p[i])) {
	//		for (int j = 0; j < n_dimensions; j++) {
	//			g[j] = x[i][j];
	//		}
	//	}
	//}
	//std::cout << std::endl;
	//std::cout << g[0] << "," << g[1] << std::endl;
	//for (int i = 0; i < stopping_criteria; i++) {
	//	populate_matrix(&r[0][0], m_particles, n_dimensions, 0, 1);
	//	populate_matrix(&s[0][0], m_particles, n_dimensions, 0, 1);
	//	for (int m = 0; m < m_particles; m++) {
	//		for (int n = 0; n < n_dimensions; n++) {
	//			v[m][n] = w * v[m][n] + c1 * r[m][n] * (p[m][n] - x[m][n]) + c2 * s[m][n] * (g[n] - x[m][n]);
	//			x[m][n] = x[m][n] + v[m][n];
	//		}
	//	}

	//	/*for (int m = 0; m < m_particles; m++) {
	//		for (int n = 0; n < n_dimensions; n++) {
	//			x[m][n] = x[m][n] + v[m][n];
	//		}
	//	}*/
	//	for (int m = 0; m < m_particles; m++) {
	//		if (objective_function(x[m]) < objective_function(p[m])) {
	//			for (int n = 0; n < n_dimensions; n++) {
	//				p[m][n] = x[m][n];
	//			}
	//		}

	//		if (objective_function(x[m]) < objective_function(g)) {
	//			for (int n = 0; n < n_dimensions; n++) {
	//				g[n] = x[m][n];
	//			}
	//		}
	//	}
	//}

	//std::cout << "(" << g[0] << ", " << g[1] << ")" << std::endl;

};
