#!/bin/zsh

# Start at the root of the project directory, i.e. where CMakeLists.txt 
# is located

# Note that this script is a little stupid: it indisciminately builds the 
# entire project

# all tests flag (includes non-unit/Catch2 tests)
FLAG_A=false
# clang-format flag
FLAG_F=false

# 1. Process flags
while getopts "af" opt; do
  case $opt in
    a)
      FLAG_A=true
      ;;
    f)
      FLAG_F=true
      ;;
    \?)
      echo "Invalid option: -$OPTARG" >&2
      ;;
  esac
done

# 2. Clean previous build directory (not necessary)
# rm -rf ./build

# 3. Configure build
if [ "$FLAG_A" = true ]; then
  cmake -DINCLUDE_TEST_MAIN=ON -B ./build 
else
  cmake -DINCLUDE_TEST_MAIN=OFF -B ./build 
fi

# 4. Run the build
cmake --build ./build

# 5. Optional (clang-)format
if [ "$FLAG_F" = true ]; then
  # Make sure pre-commit is installed first
  pre-commit install

  # Run clang-format
  pre-commit run --all-files
fi

# 6. Run the tests using CTest
./build/bin/run_tests.exe
# end-snippet