cmake_minimum_required(VERSION 3.22)
project(fpl-modern-parser)

set(CMAKE_CXX_STANDARD 20)

add_executable(fpl-modern-parser
        main.cpp main.cpp
        src/Essentials/Tokenizer.cpp
        src/Essentials/Tokenizer.h)