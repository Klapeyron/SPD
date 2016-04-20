cmake_minimum_required(VERSION 2.8)

add_definitions( -std=c++11 -Wextra -Wall -O2 )

set( ALGORITHM_LIBRARIES_DIR ${CMAKE_SOURCE_DIR}/algorithms )

add_subdirectory( algorithms )
add_subdirectory( sources )
