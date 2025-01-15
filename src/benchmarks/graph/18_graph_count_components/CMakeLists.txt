if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(18_graph_count_components cpu.cc)
    target_include_directories(18_graph_count_components PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(18_graph_count_components driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "18_graph_count_components
")
endif()
    