if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(42_sort_sorted_ranks cpu.cc)
    target_include_directories(42_sort_sorted_ranks PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(42_sort_sorted_ranks driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "42_sort_sorted_ranks
")
endif()
    