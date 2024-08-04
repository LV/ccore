CC = gcc
CFLAGS = -Wall -Wextra -g -I./include -I./lib -I./test

SRC_DIR = src
INCLUDE_DIR = include/ccore
TEST_DIR = test
LIB_DIR = lib
BUILD_DIR = build

SRC_FILES = $(wildcard $(SRC_DIR)/data_structure/list/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC_FILES))

LIB_NAME = libccore.a

TEST_SRC = $(wildcard $(TEST_DIR)/data_structure/list/*_test.c)
TEST_BINS = $(patsubst $(TEST_DIR)/%.c,$(BUILD_DIR)/%.test,$(TEST_SRC))

UNITY_SRC = $(LIB_DIR)/unity.c

.PHONY: all clean test

all: $(BUILD_DIR)/$(LIB_NAME)

$(BUILD_DIR)/$(LIB_NAME): $(OBJ_FILES)
	@mkdir -p $(@D)
	ar rcs $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

test: $(TEST_BINS)
	@for test in $(TEST_BINS) ; do ./$$test ; done

$(BUILD_DIR)/%.test: $(TEST_DIR)/%.c $(UNITY_SRC) $(BUILD_DIR)/$(LIB_NAME)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $< $(UNITY_SRC) -o $@ -L$(BUILD_DIR) -lccore

clean:
	rm -rf $(BUILD_DIR)

-include $(OBJ_FILES:.o=.d)
