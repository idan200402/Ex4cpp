# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

# Output and directories
OBJ_DIR = obj
BIN_DIR = bin
TARGET = $(BIN_DIR)/Main

# Source and object files
MAIN_SRC = main.cpp
MAIN_OBJ = $(OBJ_DIR)/main.o

# Create necessary folders
$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

# Default target
all: $(TARGET)

# Link the executable
$(TARGET): $(MAIN_OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compile main
$(MAIN_OBJ): $(MAIN_SRC) include/MyContainer.hpp
	$(CXX) $(CXXFLAGS) -c $(MAIN_SRC) -o $(MAIN_OBJ)

# Clean object and binary files
clean:
	rm -rf $(OBJ_DIR)/*.o $(TARGET)

# Build and run
run: all
	./$(TARGET)
