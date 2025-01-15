if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(37_search_find_the_closest_number_to_pi cpu.cc)
    target_include_directories(37_search_find_the_closest_number_to_pi PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(37_search_find_the_closest_number_to_pi driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "37_search_find_the_closest_number_to_pi
")
endif()
    