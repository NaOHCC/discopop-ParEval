cmake_minimum_required(VERSION 3.4.3)
project(ParEval)

# use cxx_std_17
set(CMAKE_CXX_STANDARD 17)

if (USE_OMP)
    find_package(OpenMP REQUIRED)
    message(STATUS "USE_OMP is enabled.")
    add_compile_definitions(USE_OMP)
else()
    add_compile_definitions(USE_SERIAL)
    message(STATUS "USE_OMP is disabled.")
endif()
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# DRIVER_PROBLEM_SIZE like "(1<<13)"

if (DRIVER_PROBLEM_SIZE)
    message(STATUS "DRIVER_PROBLEM_SIZE is set.")
    add_compile_definitions(DRIVER_PROBLEM_SIZE=${DRIVER_PROBLEM_SIZE})
else()
    message(FATAL "DRIVER_PROBLEM_SIZE is no set.")
endif()


add_subdirectory(src)
