cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(TinyInterpreter)

add_executable(
    TinyInterpreter 
    
    ## LEXER
    token.h token.cpp
    lexer.h lexer.cpp

    ## PARSER
    tree.h tree.cpp
    parser.h parser.cpp

    ## INTERPRETER
    main.cpp)
