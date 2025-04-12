cmake_minimum_required(VERSION 3.10)
project(physical)
add_executable(physical BrakeOutController.cpp BrakeOutWrapper.cpp GasOutController.cpp GasOutWrapper.cpp OtherSensorsInController.cpp OtherSensorsInWrapper.cpp WheelInController.cpp WheelInData.cpp WheelInWrapper.cpp WheelOutController.cpp WheelOutWrapper.cpp)
