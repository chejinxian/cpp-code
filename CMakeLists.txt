# Required CMake version
cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

# Project name
project(Cpp-Code LANGUAGES C CXX)

# minimum compiler versions

# set(GNU_MinVersion 8.0.0)
# set(AppleClang_MinVersion 11.0.0)
# set(Clang_MinVersion 6.0.0)


macro(SUBDIRLIST result curdir)
  file(GLOB children RELATIVE ${curdir} ${curdir}/*)
  set(dirlist "")
  foreach(child ${children})
    if(IS_DIRECTORY ${curdir}/${child})
      list(APPEND dirlist ${child})
    endif()
  endforeach()
  set(${result} ${dirlist})
endmacro()
# Scan module libraries
subdirlist(libs_to_build ${CMAKE_CURRENT_SOURCE_DIR}/src)

#Add subdirectories

# Build library
add_subdirectory(src)