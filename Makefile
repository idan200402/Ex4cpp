# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude -Iinclude/Iterators

# Files and folders
SRC = main.cpp
TEST_SRC = tests.cpp
OBJ_DIR = obj
BIN_DIR = bin
MAIN_OBJ = $(OBJ_DIR)/main.o
TEST_OBJ = $(OBJ_DIR)/tests.o
TARGET_MAIN = $(BIN_DIR)/Main
TARGET_TEST = $(BIN_DIR)/Tests

# Create necessary folders
$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

# Default target
Main: $(TARGET_MAIN)
	./$(TARGET_MAIN)

# Build main program
$(TARGET_MAIN): $(MAIN_OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(MAIN_OBJ): $(SRC)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# === Test Build ===
tests: $(TARGET_TEST)
	./$(TARGET_TEST)

$(TARGET_TEST): $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(TEST_OBJ): $(TEST_SRC)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# === Clean ===
clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/*
