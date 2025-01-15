if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(08_fft_split_fft cpu.cc)
    target_include_directories(08_fft_split_fft PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(08_fft_split_fft driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "08_fft_split_fft
")
endif()
    