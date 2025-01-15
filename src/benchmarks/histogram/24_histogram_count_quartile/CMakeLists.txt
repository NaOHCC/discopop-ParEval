if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(24_histogram_count_quartile cpu.cc)
    target_include_directories(24_histogram_count_quartile PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(24_histogram_count_quartile driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "24_histogram_count_quartile
")
endif()
    