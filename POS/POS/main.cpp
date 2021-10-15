#include "pos.h"

int main()
{
    const int m_particles = 20;
    const int n_dimensions = 2;
    const int stopping_criteria = 100;
    const int from = -3.;
    const int to = 3.;
    const double w = 0.8;
    const double c1 = 1.95;
    const double c2 = 1.98;

    pos<m_particles, n_dimensions> pos_obj(stopping_criteria, w, c1, c2, from, to);
};
