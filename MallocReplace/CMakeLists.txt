cmake_minimum_required(VERSION 3.21)
project(MallocReplace)

set(CMAKE_CXX_STANDARD 14)

add_executable(MallocReplace main.cpp MyMalloc.cpp MyMalloc.h)
