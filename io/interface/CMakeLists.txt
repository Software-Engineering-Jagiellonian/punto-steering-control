cmake_minimum_required(VERSION 3.10)
project(io)
add_library(interface_lib STATIC GamepadController.cpp
        GamepadInX.cpp
        GamepadInX.h
        GamepadInY.cpp
        GamepadInY.h)
target_include_directories(interface_lib PUBLIC
        ${gamepad_SOURCE_DIR}/include
        ${gamepad_BINARY_DIR}/include
)
target_link_libraries(interface_lib PUBLIC gamepad)

