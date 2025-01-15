if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(46_sparse_la_spmm cpu.cc)
    target_include_directories(46_sparse_la_spmm PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(46_sparse_la_spmm driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "46_sparse_la_spmm
")
endif()
    