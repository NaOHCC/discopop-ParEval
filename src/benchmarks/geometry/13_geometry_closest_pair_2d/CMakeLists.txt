if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(13_geometry_closest_pair_2d cpu.cc)
    target_include_directories(13_geometry_closest_pair_2d PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(13_geometry_closest_pair_2d driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "13_geometry_closest_pair_2d
")
endif()
    