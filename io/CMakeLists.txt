add_subdirectory(interface)
add_subdirectory(physical)

add_library(io STATIC
    CMakeLists.txt
    Input.h
    IOCoordinator.cpp
    IOCoordinator.h
    Output.h
)

target_include_directories(io PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
