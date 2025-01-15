if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(05_fft_inverse_fft cpu.cc)
    target_include_directories(05_fft_inverse_fft PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(05_fft_inverse_fft driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "05_fft_inverse_fft
")
endif()
    