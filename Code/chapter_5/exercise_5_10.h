
#ifndef CODE_EXERCISE_5_10_H
#define CODE_EXERCISE_5_10_H
// Problem Statement: Write the program exrp, which evaluates a reverse Polish expression from the command line, where
// each operator or operand is a separate argument. For example, 'expr 2 3 4 + *' evaluates '2 * (3 + 4)'

// Not validating input fully.

#include <ctype.h>
#include <stdlib.h>
int pop(int *tokenarray, int *i);
int len(char *s);

int expr(int argc, char *argv[]) {
    int tokenarray[argc - 1];
    int i = -1;
    while (--argc > 0) {
        char *strread = *++argv;
        int v;

        if (isdigit(*strread)){
            v = atoi(strread);
            tokenarray[++i] = v;
        } else {
            v = *strread;
            int one = pop(tokenarray, &i);
            int two = pop(tokenarray, &i);
            if (v == '+') {
                tokenarray[++i] = two + one;
            }
            if (v == '-') {
                tokenarray[++i] = two - one;
            }
            if (v == '/') {
                tokenarray[++i] = two / one;
            }
            if (v == '*') {
                tokenarray[++i] = two * one;
            }
        }
    }
    return tokenarray[i];
}

int pop(int *tokenarray, int *i) {
    return (*(tokenarray + (*i)--));
}

int len(char *s) {
    int len = 0;
    for( ;*s++ != '\0'; len++);
    return len;
}

#endif //CODE_EXERCISE_5_10_H
