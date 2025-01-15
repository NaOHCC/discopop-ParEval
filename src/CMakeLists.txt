add_library(driver driver.cpp )
include_directories(${CMAKE_SOURCE_DIR}/src)

add_subdirectory(benchmarks)
