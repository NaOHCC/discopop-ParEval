if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(19_graph_shortest_path cpu.cc)
    target_include_directories(19_graph_shortest_path PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(19_graph_shortest_path driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "19_graph_shortest_path
")
endif()
    