# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11

# Директории
BUILD_DIR = build

# Исходные файлы
STRING_SRC = s21_string.c
TEST_SRC = s21_string_test.c

# Исполняемые файлы для каждого задания
TARGET_STRLEN = $(BUILD_DIR)/Quest_1
TARGET_STRCMP = $(BUILD_DIR)/Quest_2
TARGET_STRCPY = $(BUILD_DIR)/Quest_3
TARGET_STRCAT = $(BUILD_DIR)/Quest_4

.PHONY: all strlen_tests strcmp_tests strcpy_tests strcat_tests clean test test_strlen test_strcmp test_strcpy test_strcat help

# Цель по умолчанию
all: strlen_tests strcmp_tests strcpy_tests strcat_tests

# ==================== QUEST 1: STRLEN ====================
strlen_tests: $(TARGET_STRLEN)
$(TARGET_STRLEN): $(STRING_SRC) $(TEST_SRC) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -DQUEST_1 $(STRING_SRC) $(TEST_SRC) -o $(TARGET_STRLEN)
	@echo "Build complete for Quest 1 (strlen): $(TARGET_STRLEN)"

test_strlen: strlen_tests
	@echo "=== Testing Quest 1: strlen ==="
	./$(TARGET_STRLEN)

# ==================== QUEST 2: STRCMP ====================
strcmp_tests: $(TARGET_STRCMP)
$(TARGET_STRCMP): $(STRING_SRC) $(TEST_SRC) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -DQUEST_2 $(STRING_SRC) $(TEST_SRC) -o $(TARGET_STRCMP)
	@echo "Build complete for Quest 2 (strcmp): $(TARGET_STRCMP)"

test_strcmp: strcmp_tests
	@echo "=== Testing Quest 2: strcmp ==="
	./$(TARGET_STRCMP)

# ==================== QUEST 3: STRCPY ====================
strcpy_tests: $(TARGET_STRCPY)
$(TARGET_STRCPY): $(STRING_SRC) $(TEST_SRC) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -DQUEST_3 $(STRING_SRC) $(TEST_SRC) -o $(TARGET_STRCPY)
	@echo "Build complete for Quest 3 (strcpy): $(TARGET_STRCPY)"

test_strcpy: strcpy_tests
	@echo "=== Testing Quest 3: strcpy ==="
	./$(TARGET_STRCPY)

# ==================== QUEST 4: STRCAT ====================
strcat_tests: $(TARGET_STRCAT)
$(TARGET_STRCAT): $(STRING_SRC) $(TEST_SRC) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -DQUEST_4 $(STRING_SRC) $(TEST_SRC) -o $(TARGET_STRCAT)
	@echo "Build complete for Quest 4 (strcat): $(TARGET_STRCAT)"

test_strcat: strcat_tests
	@echo "=== Testing Quest 4: strcat ==="
	./$(TARGET_STRCAT)

# ==================== ОБЩИЕ ЦЕЛИ ====================
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

test: test_strlen test_strcmp test_strcpy test_strcat

clean:
	rm -rf $(BUILD_DIR)
	@echo "Clean complete"

help:
	@echo "Available targets:"
	@echo "  all          - Build all quests"
	@echo "  test         - Run all tests"
	@echo "  clean        - Clean build directory"
	@echo ""
	@echo "Individual quest targets:"
	@echo "  strlen_tests - Build Quest_1 (strlen)"
	@echo "  strcmp_tests - Build Quest_2 (strcmp)"
	@echo "  strcpy_tests - Build Quest_3 (strcpy)"
	@echo "  strcat_tests - Build Quest_4 (strcat)"
	@echo ""
	@echo "Individual test runs:"
	@echo "  test_strlen  - Build and test Quest_1"
	@echo "  test_strcmp  - Build and test Quest_2"
	@echo "  test_strcpy  - Build and test Quest_3"
	@echo "  test_strcat  - Build and test Quest_4"

.PHONY: all clean test help