# Install script for directory: C:/Users/oliwi/wallslayers/punto-steering-control/cmake-build-debug/_deps/gamepad-src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/punto-steering-control")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "C:/Program Files/JetBrains/CLion 2024.3.5/bin/mingw/bin/objdump.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/oliwi/wallslayers/punto-steering-control/cmake-build-debug/_deps/gamepad-build/libgamepad.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  include("C:/Users/oliwi/wallslayers/punto-steering-control/cmake-build-debug/_deps/gamepad-build/CMakeFiles/gamepad_static.dir/install-cxx-module-bmi-Debug.cmake" OPTIONAL)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES "C:/Users/oliwi/wallslayers/punto-steering-control/cmake-build-debug/_deps/gamepad-src/./include/libgamepad.hpp")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/gamepad" TYPE FILE FILES
    "C:/Users/oliwi/wallslayers/punto-steering-control/cmake-build-debug/_deps/gamepad-src/./include/gamepad/binding.hpp"
    "C:/Users/oliwi/wallslayers/punto-steering-control/cmake-build-debug/_deps/gamepad-src/./include/gamepad/binding-dinput.hpp"
    "C:/Users/oliwi/wallslayers/punto-steering-control/cmake-build-debug/_deps/gamepad-src/./include/gamepad/binding-xinput.hpp"
    "C:/Users/oliwi/wallslayers/punto-steering-control/cmake-build-debug/_deps/gamepad-src/./include/gamepad/binding-linux.hpp"
    "C:/Users/oliwi/wallslayers/punto-steering-control/cmake-build-debug/_deps/gamepad-src/./include/gamepad/config.h"
    "C:/Users/oliwi/wallslayers/punto-steering-control/cmake-build-debug/_deps/gamepad-src/./include/gamepad/device.hpp"
    "C:/Users/oliwi/wallslayers/punto-steering-control/cmake-build-debug/_deps/gamepad-src/./include/gamepad/hook.hpp"
    "C:/Users/oliwi/wallslayers/punto-steering-control/cmake-build-debug/_deps/gamepad-src/./include/gamepad/hook-dinput.hpp"
    "C:/Users/oliwi/wallslayers/punto-steering-control/cmake-build-debug/_deps/gamepad-src/./include/gamepad/hook-linux.hpp"
    "C:/Users/oliwi/wallslayers/punto-steering-control/cmake-build-debug/_deps/gamepad-src/./include/gamepad/hook-xinput.hpp"
    "C:/Users/oliwi/wallslayers/punto-steering-control/cmake-build-debug/_deps/gamepad-src/./include/gamepad/log.hpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/Users/oliwi/wallslayers/punto-steering-control/cmake-build-debug/_deps/gamepad-build/libgamepad_tests.exe")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libgamepad_tests.exe" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libgamepad_tests.exe")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "C:/Program Files/JetBrains/CLion 2024.3.5/bin/mingw/bin/strip.exe" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libgamepad_tests.exe")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  include("C:/Users/oliwi/wallslayers/punto-steering-control/cmake-build-debug/_deps/gamepad-build/CMakeFiles/libgamepad_tests.dir/install-cxx-module-bmi-Debug.cmake" OPTIONAL)
endif()

