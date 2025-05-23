# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "C:/Users/oliwi/wallslayers/punto-steering-control/cmake-build-debug/_deps/gamepad-src")
  file(MAKE_DIRECTORY "C:/Users/oliwi/wallslayers/punto-steering-control/cmake-build-debug/_deps/gamepad-src")
endif()
file(MAKE_DIRECTORY
  "C:/Users/oliwi/wallslayers/punto-steering-control/cmake-build-debug/_deps/gamepad-build"
  "C:/Users/oliwi/wallslayers/punto-steering-control/cmake-build-debug/_deps/gamepad-subbuild/gamepad-populate-prefix"
  "C:/Users/oliwi/wallslayers/punto-steering-control/cmake-build-debug/_deps/gamepad-subbuild/gamepad-populate-prefix/tmp"
  "C:/Users/oliwi/wallslayers/punto-steering-control/cmake-build-debug/_deps/gamepad-subbuild/gamepad-populate-prefix/src/gamepad-populate-stamp"
  "C:/Users/oliwi/wallslayers/punto-steering-control/cmake-build-debug/_deps/gamepad-subbuild/gamepad-populate-prefix/src"
  "C:/Users/oliwi/wallslayers/punto-steering-control/cmake-build-debug/_deps/gamepad-subbuild/gamepad-populate-prefix/src/gamepad-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/oliwi/wallslayers/punto-steering-control/cmake-build-debug/_deps/gamepad-subbuild/gamepad-populate-prefix/src/gamepad-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/oliwi/wallslayers/punto-steering-control/cmake-build-debug/_deps/gamepad-subbuild/gamepad-populate-prefix/src/gamepad-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
