//
// Created by Trill on 06-12-2021.
//

#ifndef CLION_MESSAGE_H
#define CLION_MESSAGE_H

#include <iostream>
const int N =  2;

class timeout_exception{

public:
    timeout_exception(std::string s){
        _message = s;
    }

    void print(){
        std::cout << _message << std::endl;
    }
private:
    std::string _message;
};

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
