cmake_minimum_required(VERSION 3.10)
project(physical)
add_executable(physical GasOutWrapper.cpp WheelOutController.cpp WheelInWrapper.cpp OtherSensorsInController.cpp GasOutController.cpp WheelInController.cpp OtherSensorsInWrapper.cpp WheelInData.cpp BrakeOutWrapper.cpp WheelOutWrapper.cpp BrakeOutController.cpp)
