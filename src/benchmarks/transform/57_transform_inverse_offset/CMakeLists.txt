if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(57_transform_inverse_offset cpu.cc)
    target_include_directories(57_transform_inverse_offset PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(57_transform_inverse_offset driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "57_transform_inverse_offset
")
endif()
    