if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(43_sort_sort_an_array_of_structs_by_key cpu.cc)
    target_include_directories(43_sort_sort_an_array_of_structs_by_key PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(43_sort_sort_an_array_of_structs_by_key driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "43_sort_sort_an_array_of_structs_by_key
")
endif()
    