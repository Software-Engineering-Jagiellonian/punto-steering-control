file(GLOB SOURCES
    "*.cpp"
    "*.h"
    "*.txt"
)

add_library(physical STATIC ${SOURCES})
target_include_directories(physical PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
