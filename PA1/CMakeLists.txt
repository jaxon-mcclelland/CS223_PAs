cmake_minimum_required(VERSION 3.16)
project(PA1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

add_compile_options(-g -I src/)

add_executable(PA1 main.cpp 
    src/LinkedList.hpp
    src/MatchingGame.hpp 
    src/Node.hpp 
    src/Player.hpp
    src/Question.hpp
    src/MatchingGame.cpp 
    src/Node.cpp 
    src/Player.cpp
    src/Question.cpp

)
