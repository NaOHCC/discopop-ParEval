if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(55_transform_relu cpu.cc)
    target_include_directories(55_transform_relu PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(55_transform_relu driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "55_transform_relu
")
endif()
    