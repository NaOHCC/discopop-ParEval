if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(25_reduce_xor cpu.cc)
    target_include_directories(25_reduce_xor PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(25_reduce_xor driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "25_reduce_xor
")
endif()
    