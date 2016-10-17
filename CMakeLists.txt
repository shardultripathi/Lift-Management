cmake_minimum_required(VERSION 3.5)
project(COL333_A4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -march=native -Ofast")

set(SOURCE_FILES main.cpp lift_world.cpp lift_world.h)
add_executable(COL333_A4 ${SOURCE_FILES})