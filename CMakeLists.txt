cmake_minimum_required(VERSION 3.10)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(punto-steering-control)
message(STATUS "Project source dir: ${PROJECT_SOURCE_DIR}")
include_directories(${PROJECT_SOURCE_DIR})
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
        gamepad
        GIT_REPOSITORY https://github.com/univrsal/libgamepad.git
        GIT_TAG master
)

FetchContent_MakeAvailable(gamepad)

# Add subdirectories
add_subdirectory(data)
add_subdirectory(io)
add_subdirectory(logic)
add_subdirectory(tests)

# Fetch GoogleTest
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main
)
FetchContent_MakeAvailable(googletest)

# Fetch nlohmann/json
FetchContent_Declare(
        json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.12.0
)
FetchContent_MakeAvailable(json)

# Enable testing
enable_testing()

# Tests executable
add_executable(standard_tests
        tests/main.cpp
        logic/GamepadControlProcessor.cpp
        io/IOCoordinator.cpp
        tests/TestIOCoordinator.cpp
        tests/outtests.cpp
)
target_link_libraries(standard_tests
        gtest
        gtest_main
        nlohmann_json::nlohmann_json
)
include(GoogleTest)
gtest_discover_tests(standard_tests)

# Main executable
add_executable(main logic/main.cpp)

# Link main with interface_lib, gamepad and json
target_link_libraries(main
        io_lib
        interface_lib
        test_lib
        logic_lib
        gamepad
        nlohmann_json::nlohmann_json
)

message(STATUS "Gamepad source dir: ${gamepad_SOURCE_DIR}")
message(STATUS "Gamepad binary dir: ${gamepad_BINARY_DIR}")