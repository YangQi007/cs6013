cmake_minimum_required(VERSION 3.21)
project(ThreadSafeQueue)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ThreadSafeQueue
        SerialQueneTests.cpp
        SerialQueneTests.h
        SerialQueue.h)

