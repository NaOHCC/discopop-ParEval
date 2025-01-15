if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(22_histogram_count_quadrants cpu.cc)
    target_include_directories(22_histogram_count_quadrants PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(22_histogram_count_quadrants driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "22_histogram_count_quadrants
")
endif()
    