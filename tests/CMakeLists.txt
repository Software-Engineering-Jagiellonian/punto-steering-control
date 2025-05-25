cmake_minimum_required(VERSION 3.10)
project(tests)
add_executable(tests outtests.cpp main.cpp
        TestOutput.cpp
        TestOutput.h)
add_library(test_lib STATIC TestOutput.cpp)
target_include_directories(test_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
