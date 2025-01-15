if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(01_dense_la_solve cpu.cc)
    target_include_directories(01_dense_la_solve PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(01_dense_la_solve driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "01_dense_la_solve
")
endif()
    