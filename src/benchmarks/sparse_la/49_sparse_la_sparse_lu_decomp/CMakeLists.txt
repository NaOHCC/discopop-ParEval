if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(49_sparse_la_sparse_lu_decomp cpu.cc)
    target_include_directories(49_sparse_la_sparse_lu_decomp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(49_sparse_la_sparse_lu_decomp driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "49_sparse_la_sparse_lu_decomp
")
endif()
    