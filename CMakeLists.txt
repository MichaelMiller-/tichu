cmake_minimum_required(VERSION 3.1)
project(tichu CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 17)

add_library(tichu INTERFACE)
# find_package(Boost REQUIRED)
# target_sources(tichu INTERFACE …)
target_include_directories(tichu SYSTEM INTERFACE include/)

option(ENABLE_BENCHMARKS "Enable benchmarks" FALSE)

if (ENABLE_BENCHMARKS)
   message(STATUS "Benchmarks is enabled")
   add_subdirectory(benchmarks)
endif()

## to disable testing set BUILD_TESTING to false
include(CTest)
enable_testing()
add_subdirectory(tests)

