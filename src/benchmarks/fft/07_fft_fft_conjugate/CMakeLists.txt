if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(07_fft_fft_conjugate cpu.cc)
    target_include_directories(07_fft_fft_conjugate PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(07_fft_fft_conjugate driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "07_fft_fft_conjugate
")
endif()
    