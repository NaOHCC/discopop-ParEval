if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(34_scan_largest_contiguous_subarray_sum cpu.cc)
    target_include_directories(34_scan_largest_contiguous_subarray_sum PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(34_scan_largest_contiguous_subarray_sum driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "34_scan_largest_contiguous_subarray_sum
")
endif()
    