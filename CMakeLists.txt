cmake_minimum_required(VERSION 3.16)
project(euler)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS -march=native)

add_executable(euler euler.cpp)

find_package(OPENMP REQUIRED)
target_link_libraries(euler PUBLIC OpenMP::OpenMP_CXX)
