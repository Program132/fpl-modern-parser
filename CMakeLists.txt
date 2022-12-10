cmake_minimum_required(VERSION 3.22)
project(fpl-modern-parser)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Werror -ggdb3")

add_executable(fpl-modern-parser
        main.cpp main.cpp
        src/Essentials/Tokenizer.cpp
        src/Essentials/Tokenizer.h
        src/Essentials/Parser.cpp
        src/Essentials/Parser.h
        src/Essentials/Types.cpp
        src/Essentials/Types.h
        src/Essentials/Statement.cpp
        src/Essentials/Statement.h
        src/Essentials/Utils/Expecter.cpp
        src/Essentials/Utils/Expecter.h
        src/Essentials/Utils/Data.cpp
        src/Essentials/Utils/Data.h
        src/Essentials/Utils/ErrorsCodeManagement.cpp
        src/Essentials/Utils/ErrorsCodeManagement.h)