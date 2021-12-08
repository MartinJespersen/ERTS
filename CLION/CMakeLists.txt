cmake_minimum_required(VERSION 3.21)
project(CLION)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_FLAGS -pthread)
add_executable(CLION main.cpp source/message.cpp headers/message.h source/message_future.cpp headers/message_future.h source/method_request.cpp headers/method_request.h source/proxy.cpp headers/method_request.h headers/queue_impl.h source/queue_win.cpp headers/queue_win.h source/queue.cpp headers/queue.h source/scheduler.cpp headers/scheduler.h source/servant.cpp headers/servant.h headers/proxy.h)
