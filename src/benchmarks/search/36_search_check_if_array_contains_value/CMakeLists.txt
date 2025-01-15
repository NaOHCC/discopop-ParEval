if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(36_search_check_if_array_contains_value cpu.cc)
    target_include_directories(36_search_check_if_array_contains_value PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(36_search_check_if_array_contains_value driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "36_search_check_if_array_contains_value
")
endif()
    