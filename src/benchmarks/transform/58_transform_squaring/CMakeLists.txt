if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(58_transform_squaring cpu.cc)
    target_include_directories(58_transform_squaring PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(58_transform_squaring driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "58_transform_squaring
")
endif()
    