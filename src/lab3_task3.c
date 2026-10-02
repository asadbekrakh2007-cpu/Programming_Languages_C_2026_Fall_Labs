/*
 * Lab 3, Task 3
 * Name: Asadbek Rakhmatillaev
 * Student ID: 251ADB073
 *
 * Implement manual string functions:
 *   - my_strlen
 *   - my_strcpy
 *
 * Do not use <string.h>.
 */

#include <stdio.h>

// Function prototypes
int my_strlen(const char *str);
void my_strcpy(char *dest, const char *src);

int main(void) {
    char text[] = "Programming in C";
    char buffer[100];

    int len = my_strlen(text);
    my_strcpy(buffer, text);

    printf("Length: %d\n", len);
    printf("Copy: %s\n", buffer);

    return 0;
}

// Implement functions below
int my_strlen(const char *str) {
    int length = 0;

    while (str[length] != '\0') {
        length++;
    }

    return length;
}

void my_strcpy(char *dest, const char *src) {
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';
}