if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(17_graph_highest_degree cpu.cc)
    target_include_directories(17_graph_highest_degree PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(17_graph_highest_degree driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "17_graph_highest_degree
")
endif()
    