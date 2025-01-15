if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(31_scan_scan_with_min_function cpu.cc)
    target_include_directories(31_scan_scan_with_min_function PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(31_scan_scan_with_min_function driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "31_scan_scan_with_min_function
")
endif()
    