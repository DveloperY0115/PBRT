# Set target name
set(target PBRT)

# Define root directory
set(root_dir $${CMAKE_CURRENT_SOURCE_DIR}/../)

# Includes
include_directories(..)

# Sources
file(GLOB_RECURSE headers
        ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp)
file(GLOB_RECURSE sources
        ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)