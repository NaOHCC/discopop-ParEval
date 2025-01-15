if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(39_search_xor_contains cpu.cc)
    target_include_directories(39_search_xor_contains PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(39_search_xor_contains driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "39_search_xor_contains
")
endif()
    