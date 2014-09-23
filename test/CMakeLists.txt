enable_testing()

include_directories(${gtest_SOURCE_DIR}/include)

add_executable(CLionRedPencilDemo_test RedPencilRulesEngineTest.cpp)

target_link_libraries(CLionRedPencilDemo_test
    gtest_main
    CLionRedPencilDemo_lib)