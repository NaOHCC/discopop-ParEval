if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(28_reduce_smallest_odd_number cpu.cc)
    target_include_directories(28_reduce_smallest_odd_number PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(28_reduce_smallest_odd_number driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "28_reduce_smallest_odd_number
")
endif()
    