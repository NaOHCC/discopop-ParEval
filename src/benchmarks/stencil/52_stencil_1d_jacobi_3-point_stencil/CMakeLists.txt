if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(52_stencil_1d_jacobi_3-point_stencil cpu.cc)
    target_include_directories(52_stencil_1d_jacobi_3-point_stencil PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(52_stencil_1d_jacobi_3-point_stencil driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "52_stencil_1d_jacobi_3-point_stencil
")
endif()
    