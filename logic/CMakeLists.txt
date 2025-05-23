cmake_minimum_required(VERSION 3.10)
project(logic)
add_library(logic_lib STATIC GamepadControlProcessor.cpp)
target_include_directories(logic_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
