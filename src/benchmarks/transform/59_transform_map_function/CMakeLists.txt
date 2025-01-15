if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(59_transform_map_function cpu.cc)
    target_include_directories(59_transform_map_function PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(59_transform_map_function driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "59_transform_map_function
")
endif()
    