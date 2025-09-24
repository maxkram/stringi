# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11

# Папка для исполняемых файлов (относительно src/)
BUILD_DIR = ../build

# Исходные файлы (в той же директории src/)
STRING_SRC = s21_string.c
TEST_SRC = s21_string_test.c

# Исполняемые файлы
TARGET_STRLEN = $(BUILD_DIR)/Quest_1
TARGET_STRCMP = $(BUILD_DIR)/Quest_2
TARGET_STRCPY = $(BUILD_DIR)/Quest_3
TARGET_STRCAT = $(BUILD_DIR)/Quest_4
TARGET_STRCHR = $(BUILD_DIR)/Quest_5
TARGET_STRSTR = $(BUILD_DIR)/Quest_6
TARGET_STRTOK = $(BUILD_DIR)/Quest_7

# Флаги для каждого квеста
FLAGS_QUEST_1 = -DQUEST_1
FLAGS_QUEST_2 = -DQUEST_2
FLAGS_QUEST_3 = -DQUEST_3
FLAGS_QUEST_4 = -DQUEST_4
FLAGS_QUEST_5 = -DQUEST_5
FLAGS_QUEST_6 = -DQUEST_6
FLAGS_QUEST_7 = -DQUEST_7

.PHONY: all strlen_tests strcmp_tests strcpy_tests strcat_tests strchr_tests strstr_tests strtok_tests clean test

# Цель по умолчанию: собрать все тесты
all: strlen_tests strcmp_tests strcpy_tests strcat_tests strchr_tests strstr_tests strtok_tests

# === Quest 1: s21_strlen ===
strlen_tests: $(TARGET_STRLEN)

$(TARGET_STRLEN): $(STRING_SRC) $(TEST_SRC) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(FLAGS_QUEST_1) $(STRING_SRC) $(TEST_SRC) -o $(TARGET_STRLEN)
	@echo "✅ Сборка завершена: $(TARGET_STRLEN)"

# === Quest 2: s21_strcmp ===
strcmp_tests: $(TARGET_STRCMP)

$(TARGET_STRCMP): $(STRING_SRC) $(TEST_SRC) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(FLAGS_QUEST_2) $(STRING_SRC) $(TEST_SRC) -o $(TARGET_STRCMP)
	@echo "✅ Сборка завершена: $(TARGET_STRCMP)"

# === Quest 3: s21_strcpy ===
strcpy_tests: $(TARGET_STRCPY)

$(TARGET_STRCPY): $(STRING_SRC) $(TEST_SRC) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(FLAGS_QUEST_3) $(STRING_SRC) $(TEST_SRC) -o $(TARGET_STRCPY)
	@echo "✅ Сборка завершена: $(TARGET_STRCPY)"

# === Quest 4: s21_strcat ===
strcat_tests: $(TARGET_STRCAT)

$(TARGET_STRCAT): $(STRING_SRC) $(TEST_SRC) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(FLAGS_QUEST_4) $(STRING_SRC) $(TEST_SRC) -o $(TARGET_STRCAT)
	@echo "✅ Сборка завершена: $(TARGET_STRCAT)"

# === Quest 5: s21_strchr ===
strchr_tests: $(TARGET_STRCHR)

$(TARGET_STRCHR): $(STRING_SRC) $(TEST_SRC) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(FLAGS_QUEST_5) $(STRING_SRC) $(TEST_SRC) -o $(TARGET_STRCHR)
	@echo "✅ Сборка завершена: $(TARGET_STRCHR)"

# === Quest 6: s21_strstr ===
strstr_tests: $(TARGET_STRSTR)

$(TARGET_STRSTR): $(STRING_SRC) $(TEST_SRC) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(FLAGS_QUEST_6) $(STRING_SRC) $(TEST_SRC) -o $(TARGET_STRSTR)
	@echo "✅ Сборка завершена: $(TARGET_STRSTR)"

# === Quest 7: s21_strtok ===
strtok_tests: $(TARGET_STRTOK)

$(TARGET_STRTOK): $(STRING_SRC) $(TEST_SRC) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(FLAGS_QUEST_7) $(STRING_SRC) $(TEST_SRC) -o $(TARGET_STRTOK)
	@echo "✅ Сборка завершена: $(TARGET_STRTOK)"

# Создание директории build (относительно src: ../../build)
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Цель для запуска всех тестов (если исполняемые файлы уже собраны)
test:
	@echo "=== Запуск всех тестов ==="
	@./$(TARGET_STRLEN) || echo "❌ Quest_1 failed"
	@./$(TARGET_STRCMP) || echo "❌ Quest_2 failed"
	@./$(TARGET_STRCPY) || echo "❌ Quest_3 failed"
	@./$(TARGET_STRCAT) || echo "❌ Quest_4 failed"
	@./$(TARGET_STRCHR) || echo "❌ Quest_5 failed"
	@./$(TARGET_STRSTR) || echo "❌ Quest_6 failed"
	@./$(TARGET_STRTOK) || echo "❌ Quest_7 failed"

# Очистка
clean:
	rm -rf $(BUILD_DIR)
	@echo "🧹 Очистка завершена"

# Справка
help:
	@echo "🎯 Доступные цели:"
	@echo "  all          - Собрать все тесты (Quest_1..7)"
	@echo "  test         - Запустить все собранные тесты"
	@echo "  clean        - Удалить папку build"
	@echo ""
	@echo "🚀 Сборка отдельных тестов:"
	@echo "  make strlen_tests   - Собрать Quest_1 (s21_strlen)"
	@echo "  make strcmp_tests   - Собрать Quest_2 (s21_strcmp)"
	@echo "  make strcpy_tests   - Собрать Quest_3 (s21_strcpy)"
	@echo "  make strcat_tests   - Собрать Quest_4 (s21_strcat)"
	@echo "  make strchr_tests   - Собрать Quest_5 (s21_strchr)"
	@echo "  make strstr_tests   - Собрать Quest_6 (s21_strstr)"
	@echo "  make strtok_tests   - Собрать Quest_7 (s21_strtok)"