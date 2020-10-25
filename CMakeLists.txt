# CMake version
cmake_minimum_required(VERSION 3.17)

# Declare project
project(Sources/pbrt)

# Set root directory
if (NOT PBRT_ROOT)
        set(PBRT_ROOT ${PROJECT_SOURCE_DIR})
endif()

# C++ Standard - C++14
set(CMAKE_CXX_STANDARD 14)

# Some informative paths
set(LIBRARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Libraries)

# Set output directories
set(DEFAULT_CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

# Includes
include_directories(Sources)
include_directories(Libraries)
include_directories(Libraries/doctest/doctest)

# Project modules
add_subdirectory(Sources/pbrt)
add_subdirectory(Tests/UnitTests)
