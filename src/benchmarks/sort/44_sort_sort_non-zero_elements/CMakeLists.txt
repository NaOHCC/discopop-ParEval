if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(44_sort_sort_non-zero_elements cpu.cc)
    target_include_directories(44_sort_sort_non-zero_elements PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(44_sort_sort_non-zero_elements driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "44_sort_sort_non-zero_elements
")
endif()
    