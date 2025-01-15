if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(45_sparse_la_sparse_solve cpu.cc)
    target_include_directories(45_sparse_la_sparse_solve PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(45_sparse_la_sparse_solve driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "45_sparse_la_sparse_solve
")
endif()
    