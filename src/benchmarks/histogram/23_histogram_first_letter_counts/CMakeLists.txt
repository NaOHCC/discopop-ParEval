if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(23_histogram_first_letter_counts cpu.cc)
    target_include_directories(23_histogram_first_letter_counts PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(23_histogram_first_letter_counts driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "23_histogram_first_letter_counts
")
endif()
    