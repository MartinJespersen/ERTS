#include "queue.h"

queue::queue(size_t size){
    _impl = queue_impl(size);
}

void queue::put(method_request * mes){
    pthread_mutex_lock(&_mut);

    while(_impl.size() == _impl.get_max_size())
        pthread_cond_wait(&_writer_cond, &_mut);

    _impl.put(mes);

    pthread_mutex_unlock(&_mut);
    pthread_cond_signal(&_reader_cond);
}

method_request * queue::remove(){
    pthread_mutex_lock(&_mut);

    while(_impl.size() == 0)
        pthread_cond_wait(&_reader_cond, &_mut);

    method_request * i = _impl.remove();

    pthread_cond_signal(&_writer_cond);

    pthread_mutex_unlock(&_mut);

    return i;
}

