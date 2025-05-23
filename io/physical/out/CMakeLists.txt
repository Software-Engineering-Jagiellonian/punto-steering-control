cmake_minimum_required(VERSION 3.10)
project(out)
add_executable(out GasOutWrapper.cpp WheelOutController.cpp GasOutController.cpp BrakeOutWrapper.cpp WheelOutWrapper.cpp BrakeOutController.cpp)
