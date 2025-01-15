if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(15_graph_edge_count cpu.cc)
    target_include_directories(15_graph_edge_count PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(15_graph_edge_count driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "15_graph_edge_count
")
endif()
    