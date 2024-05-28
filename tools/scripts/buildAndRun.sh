#!/bin/sh

# Start at the root of the project directory, i.e. where CMakeLists.txt 
# is located

# Make sure you have permission to run script. If not, enter into sh:
# chmod +x ./tools/scripts/buildAndRun.sh

# Note that this script is a little stupid: it indisciminately builds the 
# entire project

# 1. Configure build
cmake -B ./build

# 2. Run the build
cmake --build ./build

FLAG_FORMAT=false

while getopts "format" opt; do
  case $opt in
    format)
      FLAG_FORMAT=true
      ;;
    \?)
      echo "Invalid option: -$OPTARG" >&2
      ;;
  esac
done

if [ "$FLAG_FORMAT" = true ]; then
  # Make sure pre-commit is installed first
  pre-commit install

  # Run clang-format
  pre-commit run --all-files
fi

# 4. Run the tests using CTest
./build/bin/run.exe
# end-snippet
