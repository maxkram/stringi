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
TARGET_STRCHR = $(BUILD_DIR)/Quest_5
TARGET_STRSTR = $(BUILD_DIR)/Quest_6
TARGET_STRTOK = $(BUILD_DIR)/Quest_7

.PHONY: all strlen_tests strcmp_tests strcpy_tests strcat_tests strchr_tests strstr_tests strtok_tests clean test help
.PHONY: test_strlen test_strcmp test_strcpy test_strcat test_strchr test_strstr test_strtok

# Цель по умолчанию
all: strlen_tests strcmp_tests strcpy_tests strcat_tests strchr_tests strstr_tests strtok_tests

# ==================== QUEST 1: STRLEN ====================
strlen_tests: $(TARGET_STRLEN)
$(TARGET_STRLEN): $(STRING_SRC) $(TEST_SRC) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -DQUEST_1 $(STRING_SRC) $(TEST_SRC) -o $(TARGET_STRLEN)
	@echo "Build complete for Quest 1 (strlen): $(TARGET_STRLEN)"

test_strlen: strlen_tests
	@echo "=== Testing Quest 1: strlen ==="
	./$(TARGET_STRLEN)

# ==================== QUEST 7: STRTOK ====================
strtok_tests: $(TARGET_STRTOK)
$(TARGET_STRTOK): $(STRING_SRC) $(TEST_SRC) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -DQUEST_7 $(STRING_SRC) $(TEST_SRC) -o $(TARGET_STRTOK)
	@echo "Build complete for Quest 7 (strtok): $(TARGET_STRTOK)"

test_strtok: strtok_tests
	@echo "=== Testing Quest 7: strtok ==="
	./$(TARGET_STRTOK)

# ==================== ОБЩИЕ ЦЕЛИ ====================
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

test: test_strlen test_strcmp test_strcpy test_strcat test_strchr test_strstr test_strtok

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
	@echo "  strchr_tests - Build Quest_5 (strchr)"
	@echo "  strstr_tests - Build Quest_6 (strstr)"
	@echo "  strtok_tests - Build Quest_7 (strtok)"
	@echo ""
	@echo "Individual test runs:"
	@echo "  test_strlen  - Build and test Quest_1"
	@echo "  test_strcmp  - Build and test Quest_2"
	@echo "  test_strcpy  - Build and test Quest_3"
	@echo "  test_strcat  - Build and test Quest_4"
	@echo "  test_strchr  - Build and test Quest_5"
	@echo "  test_strstr  - Build and test Quest_6"
	@echo "  test_strtok  - Build and test Quest_7"

.PHONY: all clean test help