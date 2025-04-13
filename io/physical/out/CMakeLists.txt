cmake_minimum_required(VERSION 3.10)
project(out)
add_executable(out BrakeOutController.cpp BrakeOutWrapper.cpp GasOutController.cpp GasOutWrapper.cpp WheelOutController.cpp WheelOutWrapper.cpp)
