cmake_minimum_required(VERSION 3.22)
project(fpl-modern-parser)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ -lwsock32 -lws2_32 ${CMAKE_CSS_STANDARD_LIBRARIES}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")

add_executable(fpl-modern-parser
        main.cpp main.cpp
        src/Essentials/Tokenizer.cpp
        src/Essentials/Tokenizer.h)