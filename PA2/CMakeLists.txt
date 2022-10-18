cmake_minimum_required(VERSION 3.16)
project(AVL_Tree)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

add_compile_options(-g -I src/)

add_executable(AVL_Tree main.cpp
    src/testCases.h
    src/AVL_Tree.h
    src/AVL_Node.h
    src/testCases.cpp
)
