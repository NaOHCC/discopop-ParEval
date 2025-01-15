if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(10_geometry_convex_hull cpu.cc)
    target_include_directories(10_geometry_convex_hull PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(10_geometry_convex_hull driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "10_geometry_convex_hull
")
endif()
    