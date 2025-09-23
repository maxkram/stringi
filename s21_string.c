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

char *s21_strchr(const char *str, int c) {
  char *result = NULL;

  while (*str != '\0') {
    if (*str == (char)c) {
      result = (char *)str;
      break;
    }
    str++;
  }

  if (result == NULL && (char)c == '\0') {
    result = (char *)str;
  }

  return result;
}

char *s21_strstr(const char *haystack, const char *needle) {
  char *result = NULL;

  if (needle == NULL || *needle == '\0') {
    result = (char *)haystack;
  } else {
    while (*haystack != '\0' && result == NULL) {
      const char *h = haystack;
      const char *n = needle;

      while (*h != '\0' && *n != '\0' && *h == *n) {
        h++;
        n++;
      }

      if (*n == '\0') {
        result = (char *)haystack;
      }

      if (*h == '\0') {
        break;
      }

      haystack++;
    }
  }

  return result;
}

