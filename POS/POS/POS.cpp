#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <random>
#include <string>
#include <cmath>
// using random numbers in system c is shown in assignment 2 exercise 3.1
double randMToN(double M, double N)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_real_distribution<float> dist6(M, N);
    return dist6(rng);
}

void popRandUniMatrix(double * mat, int m, int n, int from, int to) {
    srand(time(NULL));
    for(int i = 0; i<m; i++)
        for (int j = 0; j < n; j++) {
            (mat + (i * n))[j] = randMToN(from, to);
        }

}

void displayMatrix(double* mat, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << (mat + (i * n))[j] << " ";
        }
        std::cout << std::endl;
    }
        
}

float POS(float (*funcPtr)(float[]), int d, int stop, float w, float c1, float c2) {
    int dim = 2;
    return float(1);
}

double func(double* x) {
    const double e = std::exp(1.0);
    return 3*pow(1 - x[0], 2) * exp(pow(-x[0], 2) - pow(x[1] + 1, 2)) - 10 * (x[0] / 5 - pow(x[0], 3) - pow(x[1], 5)) * exp(-pow(x[0], 2) - pow(x[1], 2)) - (exp(-pow(x[0] + 1, 2) - pow(x[1], 2))) / 3;
}

int main()
{
    std::random_device dev;
    std::mt19937 rng(dev());
    
    const int m = 2;
    const int n = 3;

    double v[m][n];
    double x[m][n];
    double g[n];

    popRandUniMatrix(&x[0][0], m, n, 0, 10);
    displayMatrix(&x[0][0], m, n);
    std::cout << std::endl;
    popRandUniMatrix(&x[0][0], m, n, 0, 10);
    displayMatrix(&x[0][0], m, n);
    
    double p[m][n];
    memcpy(p, x, m * n * sizeof(double));
    std::cout << std::endl;
    displayMatrix(&p[0][0], m, n);
    std::cout << std::endl;
    double i[2] = { 0,0 };
    std::cout << func(i);

};
