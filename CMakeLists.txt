cmake_minimum_required(VERSION 3.10)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(punto-steering-control)
message(STATUS "Project source dir: ${PROJECT_SOURCE_DIR}")
include_directories(${PROJECT_SOURCE_DIR})
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add subdirectories
add_subdirectory(data)
add_subdirectory(io)
add_subdirectory(logic)
add_subdirectory(tests)


# Include FetchContent

include(FetchContent)

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
  GIT_TAG v3.12.0  # or the latest stable version
)
FetchContent_MakeAvailable(json)

# Enable testing
enable_testing()

add_executable(standard_tests
  tests/main.cpp
  tests/outtests.cpp
)

target_link_libraries(standard_tests
  gtest
  gtest_main
  nlohmann_json::nlohmann_json
)

include(GoogleTest)
# target_include_directories(build PRIVATE ${PROJECT_SOURCE_DIR})
gtest_discover_tests(standard_tests)

