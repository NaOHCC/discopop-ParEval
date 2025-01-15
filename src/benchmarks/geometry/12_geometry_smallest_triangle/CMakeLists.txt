if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(12_geometry_smallest_triangle cpu.cc)
    target_include_directories(12_geometry_smallest_triangle PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(12_geometry_smallest_triangle driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "12_geometry_smallest_triangle
")
endif()
    