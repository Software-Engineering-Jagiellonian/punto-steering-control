add_library(logic STATIC
    CMakeLists.txt
    DataProcessor.h
    GamepadControlProcessor.cpp
    GamepadControlProcessor.h
    main.cpp
)
target_include_directories(logic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(logic data io)
