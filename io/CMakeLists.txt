file(GLOB IO_SRC "*.cpp" "*.h")
add_library(io STATIC ${IO_SRC})
add_executable(program main.cpp ${IO_SRC})
