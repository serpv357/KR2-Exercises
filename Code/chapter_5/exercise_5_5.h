
#ifndef CODE_EXERCISE_5_5_H
#define CODE_EXERCISE_5_5_H
// Problem Statement: Write versions of the library functions strncpy, strncat, and strncmp, which
// operate on at most the first n characters of their argument strings. For example, strncpy(s,t,n) copies
// at most n characters of t to s. Full descriptions are in Appendix B.

#include <stdio.h>

char *strncat_new(char *s, char *t, int n) {
    char *u = s;
    for ( ;*++s != '\0'; );
    for (int i = 0; i++ < n && (*s++ = *t++) != '\0'; );
    *s = '\0';
    return u;
}

char *strncpy_new(char *s, char *ct, *n) {
    char *u = s;
    for (int i = 0; i++ < n && (*s++ = *ct++) != '\0'; );
    for (; *s != '\0'; *s++ = '\0');
    return u;
}

int strncmp_new(char *cs, char *ct, int n) {
    for (int i = 0; i++ < n && *cs != '\0' && *ct != '\0'; *cs++, *ct++){
        if (*cs < *ct)
            return -1;
        if (*cs > *ct)
            return 1;
    }
    return 0;
}



void example() {
    char s[100] = "mario";
    char t[100] = " pratt";
    char *newe = strncat_new(s, t, 4);
    printf(newe);
    printf("\n");

    char sc[100] = "mario";
    char tc[100] = " pratt";
    char *newe2 = strncpy_new(sc, tc, 5);
    printf(newe2);
    printf("\n");

    char sc2[100] = "bb";
    char tc2[100] = "bca";
    int firstGreaterThan = strncmp_new(sc2, tc2, 3);
    printf("%d", firstGreaterThan);
}
#endif //CODE_EXERCISE_5_5_H
