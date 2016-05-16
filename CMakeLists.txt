cmake_minimum_required(VERSION 2.8)

add_definitions( -std=c++11 -Wextra -Wall -O0 -g )

set( CMAKE_EXPORT_COMPILE_COMMANDS ON )
set( ALGORITHM_LIBRARIES_DIR ${CMAKE_SOURCE_DIR}/algorithms )

add_subdirectory( algorithms )
add_subdirectory( sources )
