//
// Created by Trill on 06-12-2021.
//

#include "../headers/message_future.h"

/*     HANDLE     */
message_future::message_future() :
        _mf_impl(new message_future_impl())
{
}

message_future::message_future(const message_future &f) :
        _mf_impl(f._mf_impl)
{
    _mf_impl->_count++;
}

// This method is used by the servant to create the future object
// and then afterwards use the equality operator.
message_future::message_future(const message & msg)
    : _mf_impl(new message_future_impl())
{
    _mf_impl->_msg = new message(msg);
}

void message_future::operator=(const message_future &f)
{
    delete _mf_impl->_msg;
    _mf_impl->_msg = new message(*f._mf_impl->_msg);
}

message message_future::result(const int timeout) const
{
    int msec = 0;
    clock_t before = clock();
    do {
        clock_t difference = clock() - before;
        msec = difference / CLOCKS_PER_SEC;

        if (_mf_impl->_msg != nullptr)
            return *(_mf_impl->_msg);

        sleep(0.1);
    }   while ( msec < timeout );

    throw timeout_exception("timeout has occurred in message_future");
}

message_future::~message_future()
{
    if(--_mf_impl->_count <= 0)
    {
        delete _mf_impl;
    }
}

/*     BODY     */

message_future_impl::message_future_impl() :
        _count(1),
        _msg(nullptr)
{

}

message_future_impl::~message_future_impl()
{
    delete _msg;
}