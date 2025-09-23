#include "s21_string.h"

unsigned long s21_strlen(const char *str) {
  unsigned long length = 0;

  while (str[length] != '\0') {
    length++;
  }

  return length;
}

int s21_strcmp(const char *str1, const char *str2) {
  while (*str1 && (*str1 == *str2)) {
    str1++;
    str2++;
  }

  return *(const unsigned char *)str1 - *(const unsigned char *)str2;
}

char *s21_strcpy(char *dest, const char *src) {
  char *start = dest;

  while ((*dest++ = *src++) != '\0') {
  }

  return start;
}

char *s21_strcat(char *dest, const char *src) {
  char *start = dest;

  while (*dest != '\0') {
    dest++;
  }

  while ((*dest++ = *src++) != '\0')
    ;

  return start;
}