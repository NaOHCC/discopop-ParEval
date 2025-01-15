if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(06_fft_dft cpu.cc)
    target_include_directories(06_fft_dft PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(06_fft_dft driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "06_fft_dft
")
endif()
    