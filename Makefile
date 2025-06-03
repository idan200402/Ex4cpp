# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude -Iinclude/Iterators

# Files and folders
SRC = main.cpp
OBJ_DIR = obj
BIN_DIR = bin
TARGET = $(BIN_DIR)/Main
OBJ = $(OBJ_DIR)/main.o

# Create necessary folders
$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

# Default target
Main: $(TARGET)
	./$(TARGET)

# Link object file into binary
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compile main.cpp
$(OBJ_DIR)/main.o: $(SRC) include/MyContainer.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -rf $(OBJ_DIR)/*.o $(TARGET)
