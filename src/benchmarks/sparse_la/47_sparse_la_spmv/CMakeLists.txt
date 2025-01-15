if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(47_sparse_la_spmv cpu.cc)
    target_include_directories(47_sparse_la_spmv PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(47_sparse_la_spmv driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "47_sparse_la_spmv
")
endif()
    