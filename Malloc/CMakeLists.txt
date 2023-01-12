cmake_minimum_required(VERSION 3.21)
project(Malloc)

set(CMAKE_CXX_STANDARD 17)

add_executable(Malloc main.cpp HashTable.cpp HashTable.h MyMalloc.cpp MyMalloc.h)
