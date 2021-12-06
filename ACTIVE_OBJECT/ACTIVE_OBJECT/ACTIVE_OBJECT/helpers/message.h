#pragma once 
#include <iostream>
const int N =  2;


class message 
{
public:
    message(float g[N]);
    void print();
private: 
    float _g[N]; 
};


