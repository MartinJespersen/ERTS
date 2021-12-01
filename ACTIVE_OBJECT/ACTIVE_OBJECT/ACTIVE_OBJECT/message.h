#pragma once 
#define N 2 

class message 
{
public:
    message(float g[N]) {
        for(size_t i = 0; i<N; i++)
            _g[i] = g[i];
    } 
    void print(); 
private: 
    float _g[N]; 
};

void message::print() 
{
    std::cout << "Global best: "; 
    for (int i = 0; i < N; i++)
    {
        std::cout << _g[i] << " "; 
    }
    std::cout << std::endl; 
}
