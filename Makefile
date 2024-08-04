# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g -I./src -I./lib -I./test

# Directories
SRC_DIR = src
TEST_DIR = test
LIB_DIR = lib
BUILD_DIR = build

# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/data_structure/list/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC_FILES))

# Library name
LIB_NAME = libccore.a

# Test files
TEST_SRC = $(wildcard $(TEST_DIR)/data_structure/list/*_test.c)
TEST_BINS = $(patsubst $(TEST_DIR)/%.c,$(BUILD_DIR)/%.test,$(TEST_SRC))

# Unity
UNITY_SRC = $(LIB_DIR)/unity.c

# Targets
.PHONY: all clean test

all: $(BUILD_DIR)/$(LIB_NAME)

$(BUILD_DIR)/$(LIB_NAME): $(OBJ_FILES)
	@mkdir -p $(@D)
	ar rcs $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

test: $(TEST_BINS)
	@echo "Running tests..."
	@for test in $(TEST_BINS) ; do ./$$test ; done

$(BUILD_DIR)/%.test: $(TEST_DIR)/%.c $(UNITY_SRC) $(BUILD_DIR)/$(LIB_NAME)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $< $(UNITY_SRC) $(SRC_FILES) -o $@ -L$(BUILD_DIR) -lccore

clean:
	rm -rf $(BUILD_DIR)

# Include dependencies
-include $(OBJ_FILES:.o=.d)
