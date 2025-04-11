add_library(data STATIC
    CMakeLists.txt
    Data.h
    InputType.cpp
    InputType.h
    OutputType.cpp
    OutputType.h
)

target_include_directories(data PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
