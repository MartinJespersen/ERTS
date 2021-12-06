#include "queue.h"

queue::queue(size_t size){
    pthread_cond_init(&_writer_cond, NULL);
    pthread_cond_init(&_reader_cond, NULL);

    _impl = new queue_win(size);
}

void queue::put(method_request * mes){
    pthread_mutex_lock(&_mut);

    while(_impl->size() == _impl->get_max_size())
        pthread_cond_wait(&_writer_cond, &_mut);

    _impl->put(mes);

    pthread_mutex_unlock(&_mut);
    pthread_cond_signal(&_reader_cond);
}

method_request * queue::remove(){
    pthread_mutex_lock(&_mut);

    while(_impl->size() == 0)
        pthread_cond_wait(&_reader_cond, &_mut);

    method_request * i = _impl->remove();

    pthread_cond_signal(&_writer_cond);

    pthread_mutex_unlock(&_mut);

    return i;
}

