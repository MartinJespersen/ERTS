#include "message.h"

message::message(float g[N]) {
    for(int i = 0; i<N; i++)
        _g[i] = g[i];
} 

void message::print(){
    std::cout << "Global best: ";
    for (int i = 0; i < N; i++)
    {
        std::cout << _g[i] << " ";
    }
    std::cout << std::endl;
} 