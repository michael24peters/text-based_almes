# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++11

# Directories to files
SRC_DIR := src
OBJ_DIR := tmp
BIN_DIR := bin
INC_DIR := include
LIB_DIR := lib

INCLUDES := -I./$(INC_DIR)

# Add libraries
SOURCES := $(wildcard $(SRC_DIR)/*.cc)
OBJECTS := $(patsubst $(SRC_DIR)/%.cc,$(OBJ_DIR)/%.o,$(SOURCES))
EXECUTABLE := $(BIN_DIR)/run.exe

# Default target
all: $(EXECUTABLE)

# Rule to build the target executable
$(EXECUTABLE): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to build object files from source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $< $(INCLUDES)

# Clean up build files
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR) $(LIB_DIR)

# Phony targets
.PHONY: all clean
