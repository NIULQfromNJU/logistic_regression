cmake_minimum_required(VERSION 2.3)
project(logistic_regression)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(logistic_regression ${SOURCE_FILES})
