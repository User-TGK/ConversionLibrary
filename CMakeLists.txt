## Set project information

cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(ConvertionFunctions VERSION 1.0.0 DESCRIPTION "Shared library that contains all user defined convertion functions and string representations.")
set(CMAKE_BUILD_TYPE Release)

## Setting variables for the headers and sources

file (GLOB_RECURSE public_headers "include/*.hpp")
file (GLOB_RECURSE sources "src/*.cpp")

## Creating the (.so) shared library

include_directories(${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/external)
add_library(ConvertionFunctions SHARED src/ConvertingFunctions.cpp )
target_include_directories(ConvertionFunctions PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

## Creating an installable target for the library

install(TARGETS ConvertionFunctions DESTINATION lib)
install(FILES ${public_headers} DESTINATION include/ConvertingFunctions)