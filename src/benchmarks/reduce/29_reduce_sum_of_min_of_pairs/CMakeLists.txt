if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(29_reduce_sum_of_min_of_pairs cpu.cc)
    target_include_directories(29_reduce_sum_of_min_of_pairs PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(29_reduce_sum_of_min_of_pairs driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "29_reduce_sum_of_min_of_pairs
")
endif()
    