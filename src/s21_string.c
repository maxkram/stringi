#include "s21_string.h"

size_t s21_strlen(const char *str) {
    if (str == NULL) return 0;
    size_t length = 0;

    while (str[length] != '\0') {
        length++;
    }

    return length;
}

int s21_strcmp(const char *str1, const char *str2) {
    int result = 0;

    if (str1 == NULL && str2 == NULL) {
        result = 0;
    } else if (str1 == NULL) {
        result = -1;
    } else if (str2 == NULL) {
        result = 1;
    } else {
        while (*str1 && (*str1 == *str2)) {
            str1++;
            str2++;
        }
        result = *(const unsigned char *)str1 - *(const unsigned char *)str2;
    }

    return result;
}

char *s21_strcpy(char *dest, const char *src) {
    if (dest == NULL || src == NULL) return dest;

    char *d = dest;
    while (*src != '\0') {
        *d++ = *src++;
    }
    *d = '\0';
    return dest;
}

char *s21_strcat(char *dest, const char *src) {
    if (dest == NULL || src == NULL) return dest;

    char *start = dest;

    while (*dest != '\0') {
        dest++;
    }

    while ((*dest++ = *src++) != '\0');

    return start;
}

char *s21_strchr(const char *str, int c) {
    char *result = NULL;

    if (str != NULL) {
        const char *ptr = str;

        while (*ptr != '\0' && *ptr != (char)c) {
            ptr++;
        }

        if (*ptr == (char)c) {
            result = (char *)ptr;
        }
    }

    return result;
}

char *s21_strstr(const char *haystack, const char *needle) {
    if (haystack == NULL || needle == NULL) return NULL;
    if (*needle == '\0') return (char *)haystack;

    char *result = NULL;

    while (result == NULL && *haystack != '\0') {
        const char *h = haystack;
        const char *n = needle;

        while (*h != '\0' && *n != '\0' && *h == *n) {
            h++;
            n++;
        }

        if (*n == '\0') {
            result = (char *)haystack;
        } else {
            haystack++;
        }
    }

    return result;
}

char *s21_strncpy(char *dest, const char *src, size_t n) {
    if (dest == NULL || src == NULL) return dest;

    char *start = dest;
    size_t i = 0;

    for (; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }

    for (; i < n; i++) {
        dest[i] = '\0';
    }

    return start;
}

char *s21_strtok(char *str, const char *delim) {
    if (delim == NULL) return NULL;

    static char *last = NULL;
    static char saved_str[1024];
    char *result = NULL;

    if (str != NULL) {
        size_t len = s21_strlen(str);
        if (len >= sizeof(saved_str)) {
        }
        s21_strncpy(saved_str, str, sizeof(saved_str) - 1);
        saved_str[sizeof(saved_str) - 1] = '\0';
        last = saved_str;
    }

    if (last != NULL) {
        while (*last && s21_strchr(delim, *last)) last++;

        if (*last) {
            result = last;
            while (*last && !s21_strchr(delim, *last)) last++;
            if (*last)
                *last++ = '\0';
            else
                last = NULL;
        } else {
            last = NULL;
        }
    }

    return result;
}