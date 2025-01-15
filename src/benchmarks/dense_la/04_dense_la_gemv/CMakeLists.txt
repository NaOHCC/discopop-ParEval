if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(04_dense_la_gemv cpu.cc)
    target_include_directories(04_dense_la_gemv PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(04_dense_la_gemv driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "04_dense_la_gemv
")
endif()
    