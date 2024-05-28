@echo off

REM Start at the root of the project directory, i.e. where CMakeLists.txt 
REM is located

REM Note that this script is a little stupid: it indiscriminately builds the 
REM entire project

REM 1. Configure build
cmake -B build

REM 2. Run the build
cmake --build build

REM 3. Make sure pre-commit is installed first
pre-commit install

REM 4. Run clang-format
pre-commit run --all-files

REM 5. Run the tests using CTest
build\bin\run_tests.exe
REM end-snippet