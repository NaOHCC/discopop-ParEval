if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(35_search_search_for_last_struct_by_key cpu.cc)
    target_include_directories(35_search_search_for_last_struct_by_key PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(35_search_search_for_last_struct_by_key driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "35_search_search_for_last_struct_by_key
")
endif()
    