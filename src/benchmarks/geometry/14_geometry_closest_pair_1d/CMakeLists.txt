if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(14_geometry_closest_pair_1d cpu.cc)
    target_include_directories(14_geometry_closest_pair_1d PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(14_geometry_closest_pair_1d driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "14_geometry_closest_pair_1d
")
endif()
    