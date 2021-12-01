#include "queue_win.h"
void queue_win::put(method_request * m) {
    _queue.push_back(m);
}

method_request * queue_win::remove(){
    method_request * i = _queue.front();
    _queue.pop_front();
    return i;
}
unsigned int queue_win::size() const{
    return _queue.size();
}

unsigned int queue_win::get_max_size() {
    return _max_size;
}
