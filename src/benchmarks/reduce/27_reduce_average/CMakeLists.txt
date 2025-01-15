if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(27_reduce_average cpu.cc)
    target_include_directories(27_reduce_average PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(27_reduce_average driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "27_reduce_average
")
endif()
    