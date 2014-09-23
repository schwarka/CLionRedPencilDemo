cmake_minimum_required(VERSION 2.8.4)
project(CLionRedPencilDemo)

add_subdirectory(lib)
add_subdirectory(src)
add_subdirectory(test)

add_executable(CLionRedPencilDemo main.cpp)