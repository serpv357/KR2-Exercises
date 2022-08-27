
#ifndef CODE_EXERCISE_5_6_H
#define CODE_EXERCISE_5_6_H
// Problem Statement: Rewrite appropriate programs from earlier chapters and exercises with pointers instead of
// array indexing. Good possibilities include getline (Chapters 1 and 4), atoi, itoa, and their variants
// (Chapters 2, 3, and 4), reverse (Chapter 3), and strindex and getop (Chapter 4).

#include <stdio.h>

int getline_p(char *s, int lim);
int atoi(char *s);
void itoa();
void strindex();
void getop();
// helpers
char *reverse(char *s);
int len(char *s);
// end helpers

int getline_p(char *s, int lim) {
    int c, i;
    for (i = 0; i < lim && (c = getchar()) != EOF && c != '\n'; ++i, ++*s) {
        *s = c;
    }
    if (c == '\n') {
        *s++ = c;
        ++i;
    }
    *s = '\0';
}

int atoi(char *s) {
    int i, n;
    n = 0;

    for (i = 0; *s >= '0' && *s <= '9'; ++i, *s++)
        n = 10 * n + (*s - '0');
    return n;
}

void itoa(int n, char *s) {
    int i, sign;
    char *u = s;

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        *s++ = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        *s++ = '-';
    *s = '\0';
    s = reverse(u);
}

void example() {
    int n = 12345;
    char out[6];
    itoa(n, out);
    printf(out);
}

// helpers below

char *reverse(char *s) {
    int l = len(s);
    for (int i = 0; i < l / 2; ++i) {
        char toSwap = *(s + i);
        *(s + i) = *(s + l - i - 1);
        *(s + l - i - 1) = toSwap;
    }
    return s;
}

int len(char *s) {
    int i = 0;
    while (*s++ != '\0')
        i++;
    return i;
}

#endif //CODE_EXERCISE_5_6_H
