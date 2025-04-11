cmake_minimum_required(VERSION 3.10)
project(punto-steering-control)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDebugDLL" CACHE STRING "" FORCE)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)



include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG main
)
FetchContent_MakeAvailable(googletest)

add_subdirectory(data)
add_subdirectory(io)
add_subdirectory(logic)
add_subdirectory(tests)

target_include_directories(data PUBLIC
    ${CMAKE_SOURCE_DIR}/data
)

target_include_directories(io PUBLIC
    ${CMAKE_SOURCE_DIR}/io
    ${CMAKE_SOURCE_DIR}/io/interface
    ${CMAKE_SOURCE_DIR}/io/physical
)

target_include_directories(logic PUBLIC
    ${CMAKE_SOURCE_DIR}/logic
)
enable_testing()



