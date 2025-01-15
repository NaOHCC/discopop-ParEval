if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(09_fft_fft_out_of_place cpu.cc)
    target_include_directories(09_fft_fft_out_of_place PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(09_fft_fft_out_of_place driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "09_fft_fft_out_of_place
")
endif()
    