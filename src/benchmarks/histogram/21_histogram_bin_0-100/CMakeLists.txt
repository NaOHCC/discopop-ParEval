if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(21_histogram_bin_0-100 cpu.cc)
    target_include_directories(21_histogram_bin_0-100 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(21_histogram_bin_0-100 driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "21_histogram_bin_0-100
")
endif()
    