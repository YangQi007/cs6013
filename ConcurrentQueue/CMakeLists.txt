cmake_minimum_required(VERSION 3.21)
project(ConcurrentQueue)

set(CMAKE_CXX_STANDARD 17)

add_executable(ConcurrentQueue ConcurrentQueueTest.cpp ConcurrentQueue.h)
