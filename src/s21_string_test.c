#include "s21_string.h"

#include <stdio.h>


void print_strlen_test_result(const char *test_name, const char *input, unsigned long expected,
                              unsigned long actual) {
    printf("Test: %s\n", test_name);
    printf("Input: \"%s\"\n", input ? input : "(null)");
    printf("Expected: %lu\n", expected);
    printf("Actual: %lu\n", actual);
    printf("Result: %s\n\n", expected == actual ? "SUCCESS" : "FAIL");
}

void print_strcmp_test_result(const char *test_name, const char *str1, const char *str2, int expected,
                              int actual) {
    printf("Test: %s\n", test_name);
    printf("Input: \"%s\" vs \"%s\"\n", str1 ? str1 : "(null)", str2 ? str2 : "(null)");
    int exp_sign = (expected > 0) - (expected < 0);
    int act_sign = (actual > 0) - (actual < 0);
    printf("Expected sign: %d\n", exp_sign);
    printf("Actual sign: %d\n", act_sign);
    printf("Result: %s\n\n", exp_sign == act_sign ? "SUCCESS" : "FAIL");
}

void print_strcpy_test_result(const char *test_name, const char *src, const char *expected,
                              char *actual_buffer) {
    printf("Test: %s\n", test_name);
    printf("Source: \"%s\"\n", src ? src : "(null)");
    printf("Expected: \"%s\"\n", expected ? expected : "(null)");
    printf("Actual: \"%s\"\n", actual_buffer ? actual_buffer : "(null)");
    int success = (src == NULL && actual_buffer == NULL) ||
                  (src != NULL && actual_buffer != NULL && s21_strcmp(expected, actual_buffer) == 0);
    printf("Result: %s\n\n", success ? "SUCCESS" : "FAIL");
}

void print_strcat_test_result(const char *test_name, const char *dest_initial, const char *src,
                              const char *expected, char *actual_buffer) {
    printf("Test: %s\n", test_name);
    printf("Dest initial: \"%s\"\n", dest_initial ? dest_initial : "(null)");
    printf("Source: \"%s\"\n", src ? src : "(null)");
    printf("Expected: \"%s\"\n", expected ? expected : "(null)");
    printf("Actual: \"%s\"\n", actual_buffer ? actual_buffer : "(null)");
    int success = (expected == NULL && actual_buffer == NULL) ||
                  (expected != NULL && actual_buffer != NULL && s21_strcmp(expected, actual_buffer) == 0);
    printf("Result: %s\n\n", success ? "SUCCESS" : "FAIL");
}

void print_strchr_test_result(const char *test_name, const char *str, int c, const char *expected,
                              const char *actual) {
    printf("Test: %s\n", test_name);
    printf("String: \"%s\"\n", str ? str : "(null)");
    printf("Character: '%c' (ASCII: %d)\n", (char)c, c);
    int success = 0;
    if (expected == NULL && actual == NULL) {
        success = 1;
    } else if (expected && actual && s21_strcmp(expected, actual) == 0) {
        success = 1;
    }
    printf("Expected: %s\n", expected ? expected : "NULL");
    printf("Actual: %s\n", actual ? actual : "NULL");
    printf("Result: %s\n\n", success ? "SUCCESS" : "FAIL");
}

void print_strstr_test_result(const char *test_name, const char *haystack, const char *needle,
                              const char *expected, const char *actual) {
    printf("Test: %s\n", test_name);
    printf("Haystack: \"%s\"\n", haystack ? haystack : "(null)");
    printf("Needle: \"%s\"\n", needle ? needle : "(null)");
    int success = 0;
    if (expected == NULL && actual == NULL) {
        success = 1;
    } else if (expected && actual && s21_strcmp(expected, actual) == 0) {
        success = 1;
    }
    printf("Expected: %s\n", expected ? expected : "NULL");
    printf("Actual: %s\n", actual ? actual : "NULL");
    printf("Result: %s\n\n", success ? "SUCCESS" : "FAIL");
}

void print_strtok_test_result(const char *test_name, const char *str, const char *delim,
                              const char *expected[], int expected_count, char *actual[], int actual_count) {
    printf("Test: %s\n", test_name);
    printf("String: \"%s\"\n", str ? str : "(null)");
    printf("Delimiters: \"%s\"\n", delim ? delim : "(null)");
    int success = 1;
    if (expected_count != actual_count) {
        success = 0;
    } else {
        for (int i = 0; i < expected_count; i++) {
            if ((expected[i] == NULL && actual[i] != NULL) || (expected[i] != NULL && actual[i] == NULL) ||
                (expected[i] != NULL && actual[i] != NULL && s21_strcmp(expected[i], actual[i]) != 0)) {
                success = 0;
                break;
            }
        }
    }
    printf("Expected tokens: %d\n", expected_count);
    printf("Actual tokens: %d\n", actual_count);
    printf("Result: %s\n\n", success ? "SUCCESS" : "FAIL");
}


void s21_strlen_test() {
    printf("========== QUEST 1: S21_STRLEN ==========\n\n");
    print_strlen_test_result("Normal string", "Hello", 5, s21_strlen("Hello"));
    print_strlen_test_result("Empty string", "", 0, s21_strlen(""));
    print_strlen_test_result("Single char", "A", 1, s21_strlen("A"));
}

void s21_strcmp_test() {
    printf("========== QUEST 2: S21_STRCMP ==========\n\n");
    print_strcmp_test_result("Identical", "abc", "abc", 0, s21_strcmp("abc", "abc"));
    print_strcmp_test_result("First smaller", "abc", "abd", -1, s21_strcmp("abc", "abd"));
    print_strcmp_test_result("Different lengths", "ab", "abc", -1, s21_strcmp("ab", "abc"));
}

void s21_strcpy_test() {
    printf("========== QUEST 3: S21_STRCPY ==========\n\n");
    char buffer[100];
    s21_strcpy(buffer, "Hello");
    print_strcpy_test_result("Normal copy", "Hello", "Hello", buffer);

    buffer[0] = '\0';
    s21_strcpy(buffer, "");
    print_strcpy_test_result("Empty string", "", "", buffer);

    s21_strcpy(buffer, "A");
    print_strcpy_test_result("Single char", "A", "A", buffer);
}

void s21_strcat_test() {
    printf("========== QUEST 4: S21_STRCAT ==========\n\n");
    char buffer[100] = "Hello";
    s21_strcat(buffer, " World");
    print_strcat_test_result("Normal concat", "Hello", " World", "Hello World", buffer);

    buffer[0] = '\0';
    s21_strcat(buffer, "Start");
    print_strcat_test_result("Empty dest", "", "Start", "Start", buffer);

    s21_strcpy(buffer, "Hi");
    s21_strcat(buffer, "");
    print_strcat_test_result("Empty src", "Hi", "", "Hi", buffer);
}

void s21_strchr_test() {
    printf("========== QUEST 5: S21_STRCHR ==========\n\n");
    print_strchr_test_result("Char found", "Hello", 'l', "llo", s21_strchr("Hello", 'l'));
    print_strchr_test_result("Search null", "Hello", '\0', "", s21_strchr("Hello", '\0'));
    print_strchr_test_result("Char not found", "Hello", 'z', NULL, s21_strchr("Hello", 'z'));
}

void s21_strstr_test() {
    printf("========== QUEST 6: S21_STRSTR ==========\n\n");
    print_strstr_test_result("Found substring", "Hello World", "World", "World",
                             s21_strstr("Hello World", "World"));
    print_strstr_test_result("Empty needle", "Hello", "", "Hello", s21_strstr("Hello", ""));
    print_strstr_test_result("Not found", "Hello", "xyz", NULL, s21_strstr("Hello", "xyz"));
}

void s21_strtok_test() {
    printf("========== QUEST 7: S21_STRTOK ==========\n\n");

    char buffer[256];
    char *tokens[10];
    int token_count;

    s21_strcpy(buffer, "apple,banana,cherry");
    token_count = 0;
    char *token = s21_strtok(buffer, ",");
    while (token != NULL && token_count < 10) {
        tokens[token_count++] = token;
        token = s21_strtok(NULL, ",");
    }
    const char *expected1[] = {"apple", "banana", "cherry"};
    print_strtok_test_result("Normal tokenization", "apple,banana,cherry", ",", expected1, 3, tokens,
                             token_count);

    s21_strcpy(buffer, "a,,b,,,c");
    token_count = 0;
    token = s21_strtok(buffer, ",");
    while (token != NULL && token_count < 10) {
        tokens[token_count++] = token;
        token = s21_strtok(NULL, ",");
    }
    const char *expected2[] = {"a", "b", "c"};
    print_strtok_test_result("Consecutive delimiters", "a,,b,,,c", ",", expected2, 3, tokens, token_count);

    s21_strcpy(buffer, ",,,");
    token_count = 0;
    token = s21_strtok(buffer, ",");
    while (token != NULL && token_count < 10) {
        tokens[token_count++] = token;
        token = s21_strtok(NULL, ",");
    }
    const char *expected3[] = {NULL};
    print_strtok_test_result("Only delimiters", ",,,", ",", expected3, 0, tokens, token_count);
}


int main() {
#ifdef QUEST_1
    s21_strlen_test();
#endif

#ifdef QUEST_2
    s21_strcmp_test();
#endif

#ifdef QUEST_3
    s21_strcpy_test();
#endif

#ifdef QUEST_4
    s21_strcat_test();
#endif

#ifdef QUEST_5
    s21_strchr_test();
#endif

#ifdef QUEST_6
    s21_strstr_test();
#endif

#ifdef QUEST_7
    s21_strtok_test();
#endif

#if !defined(QUEST_1) && !defined(QUEST_2) && !defined(QUEST_3) && !defined(QUEST_4) && !defined(QUEST_5) && \
    !defined(QUEST_6) && !defined(QUEST_7)
    printf("=== RUNNING ALL TESTS ===\n\n");
    s21_strlen_test();
    s21_strcmp_test();
    s21_strcpy_test();
    s21_strcat_test();
    s21_strchr_test();
    s21_strstr_test();
    s21_strtok_test();
#endif

    return 0;
}