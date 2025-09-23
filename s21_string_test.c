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

  int expected_sign = (expected > 0) ? 1 : ((expected < 0) ? -1 : 0);
  int actual_sign = (actual > 0) ? 1 : ((actual < 0) ? -1 : 0);

  if (expected_sign == actual_sign) {
    printf("Result: SUCCESS\n\n");
  } else {
    printf("Result: FAIL\n\n");
  }
}

// Функция для сравнения ожидаемого и фактического результата strchr
void print_strchr_test_result(const char *test_name, const char *str, int c,
                              const char *expected, const char *actual) {
  printf("Test: %s\n", test_name);
  printf("String: \"%s\"\n", str);
  printf("Character: '%c' (ASCII: %d)\n", (char)c, c);
  printf("Expected: %s\n", expected ? expected : "NULL");
  printf("Actual: %s\n", actual ? actual : "NULL");

  int success = 0;
  if (expected == NULL && actual == NULL) {
    success = 1;
  } else if (expected != NULL && actual != NULL &&
             s21_strcmp(expected, actual) == 0) {
    success = 1;
  }

  if (success) {
    printf("Result: SUCCESS\n\n");
  } else {
    printf("Result: FAIL\n\n");
  }
}

// Функция для сравнения ожидаемого и фактического результата strstr
void print_strstr_test_result(const char *test_name, const char *haystack,
                              const char *needle, const char *expected,
                              const char *actual) {
  printf("Test: %s\n", test_name);
  printf("Haystack: \"%s\"\n", haystack);
  printf("Needle: \"%s\"\n", needle);
  printf("Expected: %s\n", expected ? expected : "NULL");
  printf("Actual: %s\n", actual ? actual : "NULL");

  int success = 0;
  if (expected == NULL && actual == NULL) {
    success = 1;
  } else if (expected != NULL && actual != NULL &&
             s21_strcmp(expected, actual) == 0) {
    success = 1;
  }

  if (success) {
    printf("Result: SUCCESS\n\n");
  } else {
    printf("Result: FAIL\n\n");
  }
}

void print_strtok_test_result(const char *test_name, const char *str,
                             const char *delim, const char *expected[],
                             int expected_count, char *actual[],
                             int actual_count) {
  printf("Test: %s\n", test_name);
  printf("String: \"%s\"\n", str);
  printf("Delimiters: \"%s\"\n", delim);
  printf("Expected tokens: ");
  for (int i = 0; i < expected_count; i++) {
    printf("\"%s\"", expected[i]);
    if (i < expected_count - 1)
      printf(", ");
  }
  printf("\n");

  printf("Actual tokens: ");
  for (int i = 0; i < actual_count; i++) {
    printf("\"%s\"", actual[i]);
    if (i < actual_count - 1)
      printf(", ");
  }
  printf("\n");

  int success = 1;
  if (expected_count != actual_count) {
    success = 0;
  } else {
    for (int i = 0; i < expected_count && success; i++) {
      if (expected[i] == NULL && actual[i] == NULL) {
        continue;
      } else if (expected[i] != NULL && actual[i] != NULL &&
                 s21_strcmp(expected[i], actual[i]) == 0) {
        continue;
      } else {
        success = 0;
      }
    }
  }

  if (success) {
    printf("Result: SUCCESS\n\n");
  } else {
    printf("Result: FAIL\n\n");
  }
}

// Функция для тестирования s21_strlen (Quest 1)
void s21_strlen_test() {
  printf("========== QUEST 1: S21_STRLEN TESTS ==========\n\n");

  print_strlen_test_result("Normal string", "Hello", 5, s21_strlen("Hello"));
  print_strlen_test_result("Empty string", "", 0, s21_strlen(""));
}

// Функция для тестирования s21_strcmp (Quest 2)
void s21_strcmp_test() {
  printf("========== QUEST 2: S21_STRCMP TESTS ==========\n\n");

  print_strcmp_test_result("Identical strings", "hello", "hello", 0,
                           s21_strcmp("hello", "hello"));
  print_strcmp_test_result("First smaller", "apple", "banana", -1,
                           s21_strcmp("apple", "banana"));
}

// Функция для тестирования s21_strchr (Quest 5)
void s21_strchr_test() {
  printf("========== QUEST 5: S21_STRCHR TESTS ==========\n\n");

  print_strchr_test_result("Existing char", "Hello", 'e', "ello",
                           s21_strchr("Hello", 'e'));
  print_strchr_test_result("Non-existing char", "Hello", 'z', NULL,
                           s21_strchr("Hello", 'z'));
}

// Функция для тестирования s21_strstr (Quest 6)
void s21_strstr_test() {
  printf("========== QUEST 6: S21_STRSTR TESTS ==========\n\n");

  const char *haystack = "Hello, World! This is a test string.";

  // Тест 1: Поиск существующей подстроки в середине
  print_strstr_test_result("Existing substring in middle", haystack, "World",
                           "World! This is a test string.",
                           s21_strstr(haystack, "World"));

  // Тест 2: Поиск подстроки в начале
  print_strstr_test_result("Substring at beginning", haystack, "Hello",
                           "Hello, World! This is a test string.",
                           s21_strstr(haystack, "Hello"));

  // Тест 3: Поиск подстроки в конце
  print_strstr_test_result("Substring at end", haystack, "string.", "string.",
                           s21_strstr(haystack, "string."));

  // Тест 4: Поиск несуществующей подстроки
  print_strstr_test_result("Non-existing substring", haystack, "xyz", NULL,
                           s21_strstr(haystack, "xyz"));

  // Тест 5: Поиск пустой подстроки (должен вернуть haystack)
  print_strstr_test_result("Empty needle", haystack, "", haystack,
                           s21_strstr(haystack, ""));

  // Тест 6: Пустая строка haystack
  print_strstr_test_result("Empty haystack", "", "test", NULL,
                           s21_strstr("", "test"));

  // Тест 7: Обе строки пустые
  print_strstr_test_result("Both empty", "", "", "", s21_strstr("", ""));

  // Тест 8: Подстрока длиннее строки
  print_strstr_test_result("Needle longer than haystack", "short",
                           "very long needle", NULL,
                           s21_strstr("short", "very long needle"));

  // Тест 9: Поиск одного символа (аналогично strchr)
  print_strstr_test_result("Single char needle", haystack, "W",
                           "World! This is a test string.",
                           s21_strstr(haystack, "W"));

  // Тест 10: Несколько вхождений (должен найти первое)
  const char *multi = "abababab";
  print_strstr_test_result("Multiple occurrences", multi, "ab", "abababab",
                           s21_strstr(multi, "ab"));

  // Тест 11: Частичное совпадение
  print_strstr_test_result("Partial match", "abcxyz", "abc123", NULL,
                           s21_strstr("abcxyz", "abc123"));

  // Тест 12: Специальные символы в подстроке
  print_strstr_test_result("Special chars in needle", "Hello\nWorld\tTest",
                           "\nWorld", "\nWorld\tTest",
                           s21_strstr("Hello\nWorld\tTest", "\nWorld"));

  // Тест 13: Цифры в подстроке
  print_strstr_test_result("Digits in needle", "Test123!@#", "123", "123!@#",
                           s21_strstr("Test123!@#", "123"));

  // Тест 14: Краевой случай - needle равен haystack
  print_strstr_test_result("Needle equals haystack", "exact", "exact", "exact",
                           s21_strstr("exact", "exact"));

  // Тест 15: Проверка на overlapping (не должно быть проблем)
  const char *overlap = "abcabc";
  print_strstr_test_result("Overlapping search", overlap, "abc", "abcabc",
                           s21_strstr(overlap, "abc"));
}

void s21_strtok_test() {
  printf("========== QUEST 7: S21_STRTOK TESTS ==========\n\n");

  // Буферы для тестирования (так как strtok модифицирует строку)
  char buffer[256];
  char *tokens[20];
  int token_count;

  // Тест 1: Нормальное разбиение строки
  s21_strcpy(buffer, "Hello,World,Test");
  token_count = 0;
  char *token = s21_strtok(buffer, ",");
  while (token != NULL) {
    tokens[token_count++] = token;
    token = s21_strtok(NULL, ",");
  }
  const char *expected1[] = {"Hello", "World", "Test"};
  print_strtok_test_result("Normal tokenization", "Hello,World,Test", ",",
                           expected1, 3, tokens, token_count);

  // Тест 2: Несколько разделителей подряд
  s21_strcpy(buffer, "Hello,,World,,Test");
  token_count = 0;
  token = s21_strtok(buffer, ",");
  while (token != NULL) {
    tokens[token_count++] = token;
    token = s21_strtok(NULL, ",");
  }
  const char *expected2[] = {"Hello", "World", "Test"};
  print_strtok_test_result("Multiple delimiters", "Hello,,World,,Test", ",",
                           expected2, 3, tokens, token_count);

  // Тест 3: Разделители в начале и конце
  s21_strcpy(buffer, ",Hello,World,Test,");
  token_count = 0;
  token = s21_strtok(buffer, ",");
  while (token != NULL) {
    tokens[token_count++] = token;
    token = s21_strtok(NULL, ",");
  }
  const char *expected3[] = {"Hello", "World", "Test"};
  print_strtok_test_result("Delimiters at edges", ",Hello,World,Test,", ",",
                           expected3, 3, tokens, token_count);

  // Тест 4: Только разделители
  s21_strcpy(buffer, ",,,,");
  token_count = 0;
  token = s21_strtok(buffer, ",");
  while (token != NULL) {
    tokens[token_count++] = token;
    token = s21_strtok(NULL, ",");
  }
  const char *expected4[] = {}; // Пустой массив
  print_strtok_test_result("Only delimiters", ",,,,", ",", expected4, 0, tokens,
                           token_count);

  // Тест 5: Пустая строка
  s21_strcpy(buffer, "");
  token_count = 0;
  token = s21_strtok(buffer, ",");
  while (token != NULL) {
    tokens[token_count++] = token;
    token = s21_strtok(NULL, ",");
  }
  const char *expected5[] = {};
  print_strtok_test_result("Empty string", "", ",", expected5, 0, tokens,
                           token_count);

  // Тест 6: Один токен без разделителей
  s21_strcpy(buffer, "Hello");
  token_count = 0;
  token = s21_strtok(buffer, ",");
  while (token != NULL) {
    tokens[token_count++] = token;
    token = s21_strtok(NULL, ",");
  }
  const char *expected6[] = {"Hello"};
  print_strtok_test_result("Single token", "Hello", ",", expected6, 1, tokens,
                           token_count);

  // Тест 7: Несколько различных разделителей
  s21_strcpy(buffer, "Hello World\tTest\nString");
  token_count = 0;
  token = s21_strtok(buffer, " \t\n");
  while (token != NULL) {
    tokens[token_count++] = token;
    token = s21_strtok(NULL, " \t\n");
  }
  const char *expected7[] = {"Hello", "World", "Test", "String"};
  print_strtok_test_result("Multiple delimiters types",
                           "Hello World\tTest\nString", " \\t\\n", expected7, 4,
                           tokens, token_count);

  // Тест 8: Разделители как часть слов (не должны разделять)
  s21_strcpy(buffer, "Hello,World;Test:String");
  token_count = 0;
  token = s21_strtok(buffer, ",;:");
  while (token != NULL) {
    tokens[token_count++] = token;
    token = s21_strtok(NULL, ",;:");
  }
  const char *expected8[] = {"Hello", "World", "Test", "String"};
  print_strtok_test_result("Various delimiters", "Hello,World;Test:String",
                           ",;:", expected8, 4, tokens, token_count);

  // Тест 9: NULL указатель при последующих вызовах
  s21_strcpy(buffer, "First/Second/Third");
  token_count = 0;
  token = s21_strtok(buffer, "/");
  tokens[token_count++] = token;
  token = s21_strtok(NULL, "/"); // Правильный вызов с NULL
  tokens[token_count++] = token;
  token = s21_strtok(NULL, "/"); // Правильный вызов с NULL
  tokens[token_count++] = token;
  const char *expected9[] = {"First", "Second", "Third"};
  print_strtok_test_result("NULL pointer usage", "First/Second/Third", "/",
                           expected9, 3, tokens, token_count);

  // Тест 10: Чередование разных разделителей
  s21_strcpy(buffer, "A-B_C.D E");
  token_count = 0;
  token = s21_strtok(buffer, "-_ .");
  while (token != NULL) {
    tokens[token_count++] = token;
    token = s21_strtok(NULL, "-_ .");
  }
  const char *expected10[] = {"A", "B", "C", "D", "E"};
  print_strtok_test_result("Mixed delimiters", "A-B_C.D E", "-_ .", expected10,
                           5, tokens, token_count);

  // Тест 11: Краевой случай - разделитель как последний символ
  s21_strcpy(buffer, "Hello,");
  token_count = 0;
  token = s21_strtok(buffer, ",");
  while (token != NULL) {
    tokens[token_count++] = token;
    token = s21_strtok(NULL, ",");
  }
  const char *expected11[] = {"Hello"};
  print_strtok_test_result("Delimiter at end", "Hello,", ",", expected11, 1,
                           tokens, token_count);

  // Тест 12: Длинная строка с множеством токенов
  s21_strcpy(
      buffer,
      "This is a very long string with many tokens for testing purposes");
  token_count = 0;
  token = s21_strtok(buffer, " ");
  while (token != NULL) {
    tokens[token_count++] = token;
    token = s21_strtok(NULL, " ");
  }
  const char *expected12[] = {"This",   "is",     "a",       "very",
                              "long",   "string", "with",    "many",
                              "tokens", "for",    "testing", "purposes"};
  print_strtok_test_result(
      "Long string with many tokens",
      "This is a very long string with many tokens for testing purposes", " ",
      expected12, 12, tokens, token_count);
}

int main() {
#ifdef QUEST_1
  s21_strlen_test();
#endif

#ifdef QUEST_2
  s21_strcmp_test();
#endif

#ifdef QUEST_5
  s21_strchr_test();
#endif

#ifdef QUEST_6
  s21_strstr_test();
#endif

// Если не определено никаких макросов, запускаем все тесты (для отладки)
#if !defined(QUEST_1) && !defined(QUEST_2) && !defined(QUEST_5) &&             \
    !defined(QUEST_6)
  printf("=== RUNNING ALL TESTS (DEBUG MODE) ===\n\n");
  s21_strlen_test();
  s21_strcmp_test();
  s21_strchr_test();
  s21_strstr_test();
#endif

  return 0;
}