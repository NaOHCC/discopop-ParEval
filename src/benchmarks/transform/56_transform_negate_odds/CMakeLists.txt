if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/generated-code.hpp)
    add_executable(56_transform_negate_odds cpu.cc)
    target_include_directories(56_transform_negate_odds PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(56_transform_negate_odds driver OpenMP::OpenMP_CXX)
    file(WRITE "${CMAKE_BINARY_DIR}/executable.txt" "56_transform_negate_odds
")
endif()
    