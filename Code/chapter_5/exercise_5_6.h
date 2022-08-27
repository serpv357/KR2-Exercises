
#ifndef CODE_EXERCISE_5_6_H
#define CODE_EXERCISE_5_6_H
// Problem Statement: Rewrite appropriate programs from earlier chapters and exercises with pointers instead of
// array indexing. Good possibilities include getline (Chapters 1 and 4), atoi, itoa, and their variants
// (Chapters 2, 3, and 4), reverse (Chapter 3), and strindex and getop (Chapter 4).

// Note: Didn't really test most of these.

#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getline_p(char *s, int lim);
int atoi(char *s);
void itoa();
char *reverse(char *s);
int strindex(char *s, char *t);
int getop(char *s);
// helpers
int len(char *s);
int getch(void);
void ungetch(int);
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

char *reverse(char *s) {
    int l = len(s);
    for (int i = 0; i < l / 2; ++i) {
        char toSwap = *(s + i);
        *(s + i) = *(s + l - i - 1);
        *(s + l - i - 1) = toSwap;
    }
    return s;
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

int strindex(char *s, char *t) {
    int i, j, k;

    for (i = 0; *(s + i) != '\0'; i++) {
        for (j = i, k = 0; *(t + k) != '\0' && *(s + j) == *(t + k); j++, k++);
        if (k > 0 && *(t + k) == '\0')
            return i;
    }
    return -1;
}

int getop(char *s) {
    int i, c;

    while ((*s = c = getch()) == ' ' || c == '\t');
    *(s + 1) = '\0';
    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    if (isdigit(c))
        while (isdigit(*++s = c = getch()));
    if (c == '.')
        while (isdigit(*++s = c = getch()));
    *(s + i) = '\0';
    if (c != EOF)
        ungetch(c);
    return '0';
}

void example() {
    int n = 12345;
    char out[6];
    itoa(n, out);
    printf(out);
}

// helpers below

int len(char *s) {
    int i = 0;
    while (*s++ != '\0')
        i++;
    return i;
}

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

#endif //CODE_EXERCISE_5_6_H
