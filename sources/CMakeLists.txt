include_directories( ${ALGORITHM_LIBRARIES_DIR} )

add_executable( Schrage schrage.cpp )
add_executable( SchrageWithDivision schrageWithDivision.cpp )

target_link_libraries( Schrage SchrageAlgorithm )
target_link_libraries( SchrageWithDivision SchrageWithDivisionAlgorithm )

set_target_properties( Schrage PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build )
set_target_properties( SchrageWithDivision PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build )
