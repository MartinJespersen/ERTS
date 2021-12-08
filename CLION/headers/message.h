//
// Created by Trill on 06-12-2021.
//

#ifndef CLION_MESSAGE_H
#define CLION_MESSAGE_H

#include <iostream>
const int N =  2;


class message
{
public:
    message(const float g[N]);
    message(const message & msg);
    void print();
private:
    float _g[N];
};

#endif //CLION_MESSAGE_H
