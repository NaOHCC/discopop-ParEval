if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(02_dense_la_gemm cpu.cc)
    target_include_directories(02_dense_la_gemm PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(02_dense_la_gemm driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "02_dense_la_gemm
")
endif()
    