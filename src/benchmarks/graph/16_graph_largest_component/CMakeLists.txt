if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(16_graph_largest_component cpu.cc)
    target_include_directories(16_graph_largest_component PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(16_graph_largest_component driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "16_graph_largest_component
")
endif()
    