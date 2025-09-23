#include "s21_string.h"
#include <stdio.h>

// Функция для сравнения ожидаемого и фактического результата strlen
void print_strlen_test_result(const char *test_name, const char *input,
                              unsigned long expected, unsigned long actual) {
  printf("Test: %s\n", test_name);
  printf("Input: \"%s\"\n", input);
  printf("Expected: %lu\n", expected);
  printf("Actual: %lu\n", actual);

  if (expected == actual) {
    printf("Result: SUCCESS\n\n");
  } else {
    printf("Result: FAIL\n\n");
  }
}

// Функция для сравнения ожидаемого и фактического результата strcmp
void print_strcmp_test_result(const char *test_name, const char *str1,
                              const char *str2, int expected, int actual) {
  printf("Test: %s\n", test_name);
  printf("Input: \"%s\" vs \"%s\"\n", str1, str2);
  printf("Expected: %d\n", expected);
  printf("Actual: %d\n", actual);

  // Для strcmp важны только знаки: отрицательный, ноль, положительный
  int expected_sign = (expected > 0) ? 1 : ((expected < 0) ? -1 : 0);
  int actual_sign = (actual > 0) ? 1 : ((actual < 0) ? -1 : 0);

  if (expected_sign == actual_sign) {
    printf("Result: SUCCESS\n\n");
  } else {
    printf("Result: FAIL\n\n");
  }
}

void print_strcpy_test_result(const char *test_name, const char *src,
                              const char *expected, const char *actual) {
  printf("Test: %s\n", test_name);
  printf("Source: \"%s\"\n", src);
  printf("Expected: \"%s\"\n", expected);
  printf("Actual: \"%s\"\n", actual);

  // Сравниваем строки используя нашу же s21_strcmp
  if (s21_strcmp(expected, actual) == 0) {
    printf("Result: SUCCESS\n\n");
  } else {
    printf("Result: FAIL\n\n");
  }
}

void print_strcat_test_result(const char *test_name, const char *dest_init,
                              const char *src, const char *expected,
                              const char *actual) {
  printf("Test: %s\n", test_name);
  printf("Initial dest: \"%s\"\n", dest_init);
  printf("Source: \"%s\"\n", src);
  printf("Expected: \"%s\"\n", expected);
  printf("Actual: \"%s\"\n", actual);

  if (s21_strcmp(expected, actual) == 0) {
    printf("Result: SUCCESS\n\n");
  } else {
    printf("Result: FAIL\n\n");
  }
}

// Функция для тестирования s21_strlen (Quest 1)
void s21_strlen_test() {
  printf("========== QUEST 1: S21_STRLEN TESTS ==========\n\n");

  // Тест 1: Нормальная строка
  print_strlen_test_result("Normal string", "Hello, World!", 13,
                           s21_strlen("Hello, World!"));

  // Тест 2: Пустая строка
  print_strlen_test_result("Empty string", "", 0, s21_strlen(""));

  // Тест 3: Строка с одним символом
  print_strlen_test_result("Single character", "A", 1, s21_strlen("A"));

  // Тест 4: Строка с пробелами
  print_strlen_test_result("String with spaces", "   Hello   ", 11,
                           s21_strlen("   Hello   "));

  // Тест 5: Длинная строка (ИСПРАВЛЕННЫЙ - 26 символов)
  char long_str[] = "This is a long test string";
  print_strlen_test_result("Long string", long_str, 26, s21_strlen(long_str));

  // Тест 6: Строка с цифрами и символами
  print_strlen_test_result("Alphanumeric string", "Hello123!@#", 11,
                           s21_strlen("Hello123!@#"));
}

// Функция для тестирования s21_strcmp (Quest 2)
void s21_strcmp_test() {
  printf("========== QUEST 2: S21_STRCMP TESTS ==========\n\n");

  // Тест 1: Идентичные строки
  print_strcmp_test_result("Identical strings", "hello", "hello", 0,
                           s21_strcmp("hello", "hello"));

  // Тест 2: Первая строка меньше второй
  print_strcmp_test_result("First string smaller", "apple", "banana", -1,
                           s21_strcmp("apple", "banana"));

  // Тест 3: Первая строка больше второй
  print_strcmp_test_result("First string larger", "zebra", "apple", 1,
                           s21_strcmp("zebra", "apple"));

  // Тест 4: Пустые строки
  print_strcmp_test_result("Both empty strings", "", "", 0, s21_strcmp("", ""));

  // Тест 5: Первая строка пустая
  print_strcmp_test_result("First string empty", "", "hello", -1,
                           s21_strcmp("", "hello"));

  // Тест 6: Вторая строка пустая
  print_strcmp_test_result("Second string empty", "hello", "", 1,
                           s21_strcmp("hello", ""));

  // Тест 7: Строки разной длины
  print_strcmp_test_result("Different length", "hello", "hello world", -1,
                           s21_strcmp("hello", "hello world"));

  // Тест 8: Различие в регистре
  print_strcmp_test_result("Case difference", "Hello", "hello", -1,
                           s21_strcmp("Hello", "hello"));
}

void s21_strcpy_test() {
  printf("========== QUEST 3: S21_STRCPY TESTS ==========\n\n");

  char dest[100];

  const char *src1 = "Hello, World!";
  s21_strcpy(dest, src1);
  print_strcpy_test_result("Normal string", src1, src1, dest);

  const char *src2 = "";
  s21_strcpy(dest, src2);
  print_strcpy_test_result("Empty string", src2, src2, dest);

  const char *src3 = "A";
  s21_strcpy(dest, src3);
  print_strcpy_test_result("Single character", src3, src3, dest);

  const char *src4 = "   Hello   ";
  s21_strcpy(dest, src4);
  print_strcpy_test_result("String with spaces", src4, src4, dest);

  const char *src5 = "This is a very long string for testing strcpy function";
  s21_strcpy(dest, src5);
  print_strcpy_test_result("Long string", src5, src5, dest);

  const char *src6 = "Hello\tWorld\nTest\r";
  s21_strcpy(dest, src6);
  print_strcpy_test_result("Special characters", src6, src6, dest);

  const char *src7 = "Test123!@#";
  s21_strcpy(dest, src7);
  print_strcpy_test_result("Alphanumeric string", src7, src7, dest);

  const char *src8 = "Test return value";
  char *result = s21_strcpy(dest, src8);
  printf("Test: Return value check\n");
  printf("Source: \"%s\"\n", src8);
  printf("Expected: Pointer to destination buffer\n");
  printf("Actual: Pointer %s destination buffer\n",
         (result == dest) ? "to" : "NOT to");
  if (result == dest) {
    printf("Result: SUCCESS\n\n");
  } else {
    printf("Result: FAIL\n\n");
  }
}

void s21_strcat_test() {
  printf("========== QUEST 4: S21_STRCAT TESTS ==========\n\n");

  char dest[100];

  s21_strcpy(dest, "Hello");
  s21_strcat(dest, ", World!");
  print_strcat_test_result("Normal concatenation", "Hello", ", World!",
                           "Hello, World!", dest);

  s21_strcpy(dest, "");
  s21_strcat(dest, "Hello");
  print_strcat_test_result("Empty dest", "", "Hello", "Hello", dest);

  s21_strcpy(dest, "Hello");
  s21_strcat(dest, "");
  print_strcat_test_result("Empty source", "Hello", "", "Hello", dest);

  s21_strcpy(dest, "");
  s21_strcat(dest, "");
  print_strcat_test_result("Both empty", "", "", "", dest);

  s21_strcpy(dest, "Start");
  s21_strcat(dest, " ");
  s21_strcat(dest, "Middle");
  s21_strcat(dest, " ");
  s21_strcat(dest, "End");
  print_strcat_test_result("Multiple concatenations", "Start", " Middle End",
                           "Start Middle End", dest);

  s21_strcpy(dest, "This is a long destination string");
  s21_strcat(dest, " and this is a long source string");
  print_strcat_test_result(
      "Long strings", "This is a long destination string",
      " and this is a long source string",
      "This is a long destination string and this is a long source string",
      dest);

  s21_strcpy(dest, "Line1");
  s21_strcat(dest, "\nLine2");
  s21_strcat(dest, "\tTab");
  print_strcat_test_result("Special characters", "Line1", "\nLine2\tTab",
                           "Line1\nLine2\tTab", dest);

  s21_strcpy(dest, "Test");
  s21_strcat(dest, "123");
  s21_strcat(dest, "!@#");
  print_strcat_test_result("Alphanumeric", "Test", "123!@#", "Test123!@#",
                           dest);
}

int main() {
#ifdef QUEST_1
  // Запуск только тестов для Quest 1 (strlen)
  s21_strlen_test();
#endif

#ifdef QUEST_2
  // Запуск только тестов для Quest 2 (strcmp)
  s21_strcmp_test();
#endif

#ifdef QUEST_3
  // Запуск только тестов для Quest 3 (strcpy)
  s21_strcpy_test();
#endif

#ifdef QUEST_4
  s21_strcat_test();
#endif

#if !defined(QUEST_1) && !defined(QUEST_2) && !defined(QUEST_3) &&             \
    !defined(QUEST_4)
  printf("=== RUNNING ALL TESTS (DEBUG MODE) ===\n\n");
  s21_strlen_test();
  s21_strcmp_test();
  s21_strcpy_test();
  s21_strcat_test();
#endif

  return 0;
}