cmake_minimum_required(VERSION 3.20)
project(matvec LANGUAGES CXX)

add_library(matvec INTERFACE)
target_include_directories(matvec INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

# detect top-level to control tests
if (CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
  option(MATVEC_BUILD_TESTS "Build matvec tests" ON)
else()
  option(MATVEC_BUILD_TESTS "Build matvec tests" OFF)
endif()

if (MATVEC_BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()
