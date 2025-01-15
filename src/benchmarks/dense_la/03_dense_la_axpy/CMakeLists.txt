if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(03_dense_la_axpy cpu.cc)
    target_include_directories(03_dense_la_axpy PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(03_dense_la_axpy driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "03_dense_la_axpy
")
endif()
    