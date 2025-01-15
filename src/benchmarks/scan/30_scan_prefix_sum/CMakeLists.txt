if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(30_scan_prefix_sum cpu.cc)
    target_include_directories(30_scan_prefix_sum PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(30_scan_prefix_sum driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "30_scan_prefix_sum
")
endif()
    