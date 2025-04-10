file(GLOB TEST_SRC "test_*.cpp")  

add_executable(tests ${TEST_SRC})

target_link_libraries(tests gtest gtest_main io)

enable_testing()  
target_link_options(tests PRIVATE /NODEFAULTLIB:libcmtd.lib)
add_test(NAME MyTests COMMAND tests)
