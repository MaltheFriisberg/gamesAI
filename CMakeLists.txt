cmake_minimum_required(VERSION 3.7)
project(AI)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp week1/week1.cpp week1/week1.h week2/Cell.cpp week2/Cell.h cmake-build-debug/week4/Point.cpp cmake-build-debug/week4/Astar.cpp cmake-build-debug/week4/Astar.h)
add_executable(AI ${SOURCE_FILES})