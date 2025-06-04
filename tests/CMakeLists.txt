cmake_minimum_required(VERSION 3.10)
project(tests)

add_library(test_lib STATIC
        TestOutput.cpp
        TestIOCoordinator.cpp
)

target_include_directories(test_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(tests outtests.cpp main.cpp
        TestOutput.cpp
        TestIOCoordinator.cpp
)

target_include_directories(tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(tests
        interface_lib
        logic_lib
        io_lib
        data_lib
        test_lib
        gtest
        gtest_main
        gmock
        gmock_main
)

include(GoogleTest)
gtest_discover_tests(tests)
