if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(11_geometry_convex_hull_perimeter cpu.cc)
    target_include_directories(11_geometry_convex_hull_perimeter PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(11_geometry_convex_hull_perimeter driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "11_geometry_convex_hull_perimeter
")
endif()
    