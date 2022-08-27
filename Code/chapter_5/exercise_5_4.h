
#ifndef CODE_EXERCISE_5_4_H
#define CODE_EXERCISE_5_4_H
// Problem Statement: Write the function 'strend(s,t)' which returns 1 if the string t occurs at the end of the string s,
// and zero otherwise.

#include <stdio.h>
int len(char *s) {
    int len = 0;
    for( ;*s++ != '\0'; ++len);
    return len;
}

int strend(char *s, char *t) {
    s += len(s) - len(t);

    for ( ;*t != '\0'; s++, t++) {
        if (*s != *t)
            return 0;
    }
    return 1;
}

void example() {
    char str1[] = "Peat";
    char str2[] = "eat";
    int twoInOne = strend(str1, str2);
    printf("%d", twoInOne);
}

#endif //CODE_EXERCISE_5_4_H
