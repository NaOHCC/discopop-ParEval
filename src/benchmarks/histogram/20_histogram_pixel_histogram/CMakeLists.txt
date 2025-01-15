if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(20_histogram_pixel_histogram cpu.cc)
    target_include_directories(20_histogram_pixel_histogram PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(20_histogram_pixel_histogram driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "20_histogram_pixel_histogram
")
endif()
    