
#ifndef EXERCISE_5_2_H
#define EXERCISE_5_2_H

#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Problem Statement:
// Write getfloat, the floating-point analog of getint. What type does getfloat return as its function value?
// Answer:
// getfloat returns an int with either the integer value of the last read character (if successful), or 0

#define BUFSIZE 100
#define SIZE 4

char buf[BUFSIZE];
int bufp = 0;

int getch(void);

void ungetch(int);

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/* getint:  get next integer from input into *pn */
int getint(int *pn) {
    int c, sign;
    while (isspace(c = getch()))   /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);  /* it is not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0; isdigit(c), c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

int getfloat(float *pn) {
    int c;
    int sign;

    while (isspace(c = getch()));
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    if (!isdigit(c) && c != '.') {
        ungetch(c);
        return 0;
    }
    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = 10 * *pn + (c - '0');
    }
    if (c == '.') {
        c = getch();
        for (float i = 10; isdigit(c); c = getch()) {
            *pn = *pn + ((float) (c - '0')) / i;
            i *= 10;
        }
    }
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

void example() {
    // Each entered float is put into this new array
    int n;
    float array[SIZE];
    for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++);
}

#endif EXERCISE_5_2_H
