
#ifndef CODE_EXERCISE_5_3_H
#define CODE_EXERCISE_5_3_H
// Problem Statement:
// Write a pointer version fo the function 'strcat' that we showed in Chapter 2. 'strcat(s,t)' copies the string t
// to the end of s.

#include <stdio.h>

void strcat(char *s, char *t) {
    while (*++s != '\0');
    while ((*s++ = *t++) != '\0');
    *s = '\0';
}

void example() {
    char first[] = "wee";
    char second[] = "woo";
    strcat(first, second);
    printf(first);
}

#endif //CODE_EXERCISE_5_3_H
