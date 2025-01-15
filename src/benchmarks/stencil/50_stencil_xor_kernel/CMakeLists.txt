if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(50_stencil_xor_kernel cpu.cc)
    target_include_directories(50_stencil_xor_kernel PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(50_stencil_xor_kernel driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "50_stencil_xor_kernel
")
endif()
    