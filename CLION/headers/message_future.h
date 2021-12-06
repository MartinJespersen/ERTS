//
// Created by Trill on 06-12-2021.
//

#ifndef CLION_MESSAGE_FUTURE_H
#define CLION_MESSAGE_FUTURE_H

#pragma once

#include "message.h"
#include "time.h"
#include "stdio.h"

#ifdef __unix__
# include <unistd.h>
#elif defined _WIN32
#include <windows.h>
#define sleep(x) Sleep(1000 * (x))
#endif

class message_future_impl
{
    friend class message_future;
private:
    message_future_impl();
    message * get_message();
    ~message_future_impl();

    int _count;
    message * _msg;
};

class message_future
{
public:
    message_future();
    message_future(const message_future &f);
    message_future(const message &msg);
    void operator=(const message_future &f);
    message result(const int timeout = 0) const;
    ~message_future();

private:
    message_future_impl * _mf_impl;
};

#endif //CLION_MESSAGE_FUTURE_H
