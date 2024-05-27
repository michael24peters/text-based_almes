# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name
project(Almes)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the output directories for binaries and libraries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Set the output directories for executables
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/build/bin)

# Include directories (plus header-only version of Catch2)
include_directories(${CMAKE_SOURCE_DIR}/include)

# Set the header files
set(HEADER_FILES ${CMAKE_SOURCE_DIR}/include/character.h
    ${CMAKE_SOURCE_DIR}/include/npc.h)

# Set the source files
set(SOURCE_FILES ${CMAKE_SOURCE_DIR}/src/character.cc
    ${CMAKE_SOURCE_DIR}/src/npc.cc)

# Set the test files
set(TEST_FILES ${CMAKE_SOURCE_DIR}/tests/test_char.cc
    ${CMAKE_SOURCE_DIR}/tests/test_npc.cc)

# Add the main executable
add_executable(run.exe ${CMAKE_SOURCE_DIR}/src/main.cc ${HEADER_FILES})

# Add the test executable
add_executable(run_tests.exe ${TEST_FILES} ${HEADER_FILES} ${SOURCE_FILES})

# Add compiler flags
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_compile_options(
        -Wall          # Enable all warnings
        -Wextra        # Enable extra warnings
        -Werror        # Treat all warnings as errors
        -pedantic      # Enforce strict ISO C++ compliance
        -O2            # Optimize for speed (use -O3 for maximum optimization)
        -g             # Generate debug information
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options(
        /W4            # Enable all level 4 warnings
        /WX            # Treat all warnings as errors
        /O2            # Optimize for speed
        /Zi            # Generate debug information
    )
endif()
