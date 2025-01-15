if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(38_search_find_the_first_even_number cpu.cc)
    target_include_directories(38_search_find_the_first_even_number PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(38_search_find_the_first_even_number driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "38_search_find_the_first_even_number
")
endif()
    