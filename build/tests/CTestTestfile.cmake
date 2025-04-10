# CMake generated Testfile for 
# Source directory: C:/Users/oliwi/projects/punto-steering-control1/punto-steering-control/punto-steering-control/tests
# Build directory: C:/Users/oliwi/projects/punto-steering-control1/punto-steering-control/punto-steering-control/build/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(MyTests "C:/Users/oliwi/projects/punto-steering-control1/punto-steering-control/punto-steering-control/build/tests/Debug/tests.exe")
  set_tests_properties(MyTests PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/oliwi/projects/punto-steering-control1/punto-steering-control/punto-steering-control/tests/CMakeLists.txt;9;add_test;C:/Users/oliwi/projects/punto-steering-control1/punto-steering-control/punto-steering-control/tests/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(MyTests "C:/Users/oliwi/projects/punto-steering-control1/punto-steering-control/punto-steering-control/build/tests/Release/tests.exe")
  set_tests_properties(MyTests PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/oliwi/projects/punto-steering-control1/punto-steering-control/punto-steering-control/tests/CMakeLists.txt;9;add_test;C:/Users/oliwi/projects/punto-steering-control1/punto-steering-control/punto-steering-control/tests/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(MyTests "C:/Users/oliwi/projects/punto-steering-control1/punto-steering-control/punto-steering-control/build/tests/MinSizeRel/tests.exe")
  set_tests_properties(MyTests PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/oliwi/projects/punto-steering-control1/punto-steering-control/punto-steering-control/tests/CMakeLists.txt;9;add_test;C:/Users/oliwi/projects/punto-steering-control1/punto-steering-control/punto-steering-control/tests/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(MyTests "C:/Users/oliwi/projects/punto-steering-control1/punto-steering-control/punto-steering-control/build/tests/RelWithDebInfo/tests.exe")
  set_tests_properties(MyTests PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/oliwi/projects/punto-steering-control1/punto-steering-control/punto-steering-control/tests/CMakeLists.txt;9;add_test;C:/Users/oliwi/projects/punto-steering-control1/punto-steering-control/punto-steering-control/tests/CMakeLists.txt;0;")
else()
  add_test(MyTests NOT_AVAILABLE)
endif()
