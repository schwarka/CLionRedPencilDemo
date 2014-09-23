cmake_minimum_required(VERSION 2.8.4)
project(CLionRedPencilDemo)

add_subdirectory(lib/gtest-1.7.0)
add_subdirectory(src)
add_subdirectory(test)

add_executable(CLionRedPencilDemo main.cpp)

target_link_libraries(CLionRedPencilDemo CLionRedPencilDemo_lib)

add_custom_command(TARGET CLionRedPencilDemo
    POST_BUILD
    COMMAND CLionRedPencilDemo_test
    DEPENDS CLionRedPencilDemo_test
)