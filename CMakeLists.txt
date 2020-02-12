cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(TinyInterpreter)

add_executable(TinyInterpreter 
    main.cpp 
    token.h token.cpp
    lexer.h lexer.cpp
    common.h)
