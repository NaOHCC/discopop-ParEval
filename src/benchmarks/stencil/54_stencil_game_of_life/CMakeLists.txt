if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(54_stencil_game_of_life cpu.cc)
    target_include_directories(54_stencil_game_of_life PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(54_stencil_game_of_life driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "54_stencil_game_of_life
")
endif()
    