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

# 3. Optional (clang-)format
FLAG_F=false

while getopts "f" opt; do
  case $opt in
    f)
      FLAG_F=true
      ;;
    \?)
      echo "Invalid option: -$OPTARG" >&2
      ;;
  esac
done

if [ "$FLAG_F" = true ]; then
  # Make sure pre-commit is installed first
  pre-commit install

  # Run clang-format
  pre-commit run --all-files
fi

# 4. Run the tests using CTest
./build/bin/run.exe
# end-snippet
