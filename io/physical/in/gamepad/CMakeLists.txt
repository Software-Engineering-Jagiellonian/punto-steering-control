cmake_minimum_required(VERSION 3.10)
project(gamepad)
add_executable(gamepad GamepadWrapper.cpp GamepadData.cpp GamepadController.cpp)
