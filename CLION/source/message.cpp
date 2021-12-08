//
// Created by Trill on 06-12-2021.
//

#include "../headers/message.h"

message::message(const float g[N]) {
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

message::message(const message & mes) {
    for (int i = 0; i < N; i++){
        _g[i] = mes._g[i];
    }
}
