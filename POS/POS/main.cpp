#include "pos.h"
#include "random_generator.h"

int main()
{
    const int m_particles = 20;
    const int n_dimensions = 2;
    const int stopping_criteria = 100;
    const int from = -3;
    const int to = 3;
    const double w = 0.8;
    const double c1 = 1.95;
    const double c2 = 1.98;

    /*int min = 0;
    int max = 7; 
    std::cout.precision(5); 
    random_generator r_gen{};
    for (int i = 0; i < 100; i++)
    {
        double value = r_gen.nextRand(min, max);
        //std::cout << "Value: " << value << std::endl; 

        if (value > max || value < min)
        {
            std::cout << "ERROR!" << std::endl; 
        }
    }*/

    pos<m_particles, n_dimensions> pos_obj(stopping_criteria, w, c1, c2, from, to);

    return 0;
};
