cmake_minimum_required(VERSION 3.17)
project(p2)

set(CMAKE_CXX_STANDARD 14)

set(GCC_COVERAGE_COMPILE_FLAGS "-ansi -pedantic -Wall -Werror -std=c++11")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

add_executable(p2 bst_test.cpp BST.h)