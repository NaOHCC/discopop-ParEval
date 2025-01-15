if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(41_sort_k-th_smallest_element cpu.cc)
    target_include_directories(41_sort_k-th_smallest_element PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(41_sort_k-th_smallest_element driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "41_sort_k-th_smallest_element
")
endif()
    