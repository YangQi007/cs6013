cmake_minimum_required(VERSION 3.21)
project(OpenMp)

set(CMAKE_CXX_STANDARD 14)

add_executable(OpenMp main.cpp parallelSum.h)
find_package(OpenMP REQUIRED)
target_link_libraries(${PROJECT_NAME} ${OpenMP_CXX_LIBRARIES})
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()
