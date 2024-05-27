#!/bin/zsh

# Start at the root of the project directory, i.e. where CMakeLists.txt 
# is located

# Note that this script is a little stupid: it indisciminately builds the 
# entire project

# 1. Configure build
cmake -B ./build

# 2. Run the actual build
cmake --build ./build

# 3. Make sure pre-commit is installed first
pre-commit install

# 3. Run clang-format
pre-commit run --all-files

# 4. Run the tests using CTest
./build/bin/run_tests.exe
# end-snippet