if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(53_stencil_2d_jacobi_5-point_stencil cpu.cc)
    target_include_directories(53_stencil_2d_jacobi_5-point_stencil PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(53_stencil_2d_jacobi_5-point_stencil driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "53_stencil_2d_jacobi_5-point_stencil
")
endif()
    