if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(48_sparse_la_sparse_axpy cpu.cc)
    target_include_directories(48_sparse_la_sparse_axpy PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(48_sparse_la_sparse_axpy driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "48_sparse_la_sparse_axpy
")
endif()
    