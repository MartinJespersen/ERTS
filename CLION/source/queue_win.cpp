//
// Created by Trill on 06-12-2021.
//

#include "../headers/queue_win.h"

queue_win::queue_win(size_t max_size): _max_size(max_size){}

void queue_win::put(method_request * m) {
    _queue.push_back(m);
}

method_request * queue_win::remove(){
    method_request * i = _queue.front();
    _queue.pop_front();
    return i;
}
size_t queue_win::size() const{
    return _queue.size();
}

size_t queue_win::get_max_size() {
    return _max_size;
}