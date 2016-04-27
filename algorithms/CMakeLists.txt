add_library( SchrageAlgorithm SchrageAlgorithm.cpp )
add_library( SchrageWithDivisionAlgorithm SchrageWithDivisionAlgorithm.cpp )
add_library( CalierBlocks CalierBlocks.cpp )
add_library( CalierAlgorithm CalierAlgorithm.cpp )

target_link_libraries( CalierAlgorithm CalierBlocks SchrageWithDivisionAlgorithm SchrageAlgorithm )
