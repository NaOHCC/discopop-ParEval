if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(26_reduce_product_of_inverses cpu.cc)
    target_include_directories(26_reduce_product_of_inverses PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(26_reduce_product_of_inverses driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "26_reduce_product_of_inverses
")
endif()
    