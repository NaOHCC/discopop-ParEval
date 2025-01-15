if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(40_sort_sort_an_array_of_complex_numbers_by_magnitude cpu.cc)
    target_include_directories(40_sort_sort_an_array_of_complex_numbers_by_magnitude PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(40_sort_sort_an_array_of_complex_numbers_by_magnitude driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "40_sort_sort_an_array_of_complex_numbers_by_magnitude
")
endif()
    