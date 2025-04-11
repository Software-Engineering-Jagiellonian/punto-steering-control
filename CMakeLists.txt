cmake_minimum_required(VERSION 3.10)

project(punto-steering-control)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

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
  GIT_TAG v3.11.2  # or the latest stable version
)
FetchContent_MakeAvailable(json)

# Enable testing
enable_testing()
