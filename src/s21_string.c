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

    while ((*dest++ = *src++) != '\0');

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

char *s21_strtok(char *str, const char *delim) {
    static char *last = NULL;
    static char saved_str[1024];
    char *result = NULL;

    if (delim == NULL) return NULL;
    if (str == NULL && last == NULL) return NULL;

    int deliDict[256] = {0};
    for (const char *d = delim; *d != '\0'; d++) {
        deliDict[(unsigned char)*d] = 1;
    }
    if (str != NULL) {
        if (s21_strlen(str) < sizeof(saved_str)) {
            s21_strcpy(saved_str, str);
            last = saved_str;
        } else {
            last = NULL;
        }
    }
    if (last == NULL || *last == '\0') {
        last = NULL;
        return NULL;
    }

    while (*last != '\0' && deliDict[(unsigned char)*last]) {
        last++;
    }

    if (*last == '\0') {
        last = NULL;
        return NULL;
    }

    result = last;
    while (*last != '\0' && !deliDict[(unsigned char)*last]) {
        last++;
    }

    if (*last != '\0') {
        *last = '\0';
        last++;
    } else {
        last = NULL;
    }

    return result;
}