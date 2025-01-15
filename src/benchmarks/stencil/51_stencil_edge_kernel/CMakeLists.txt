if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(51_stencil_edge_kernel cpu.cc)
    target_include_directories(51_stencil_edge_kernel PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(51_stencil_edge_kernel driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "51_stencil_edge_kernel
")
endif()
    