if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(32_scan_sum_of_prefix_sum_array cpu.cc)
    target_include_directories(32_scan_sum_of_prefix_sum_array PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(32_scan_sum_of_prefix_sum_array driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "32_scan_sum_of_prefix_sum_array
")
endif()
    