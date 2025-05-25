cmake_minimum_required(VERSION 3.10)
project(io)
add_subdirectory(interface) #otherwise interface makelist is ignored
add_library(io_lib STATIC IOCoordinator.cpp)
target_include_directories(io_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
