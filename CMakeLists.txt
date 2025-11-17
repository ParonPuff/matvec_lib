cmake_minimum_required(VERSION 3.20)

project(matlib LANGUAGES CXX)

add_library(matlib INTERFACE)

target_include_directories(matlib INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Detect if matlib is the top-level project (standalone mode)
set(MATLIB_STANDALONE OFF)
if (CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
    set(MATLIB_STANDALONE ON)
endif()

# Only add tests if:
#   - We're the top-level project (matlib standalone), OR
#   - A parent explicitly enables MATLIB_BUILD_TESTS
option(MATLIB_BUILD_TESTS "Build tests for matlib" ${MATLIB_STANDALONE})

if (MATLIB_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
