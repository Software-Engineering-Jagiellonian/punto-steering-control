file(GLOB IO_SRC "*.cpp" "*.h" "interface/*.cpp" "interface/*.h")

add_library(interface STATIC ${IO_SRC})
target_include_directories(interface PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/interface
)
