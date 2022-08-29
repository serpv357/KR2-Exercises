
#ifndef CODE_EXERCISE_5_7_H
#define CODE_EXERCISE_5_7_H
// Problem Statement: Rewrite readlines to store lines in an array supplied by main, rather than by calling
// alloc to maintain storage. How much faster is the program?

// Code below. I'm not going to test the speed vs original right now, would like to move forward with reading rest of book.

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 1000

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *lineptr[MAXLINES];

void writelines(char *lineptr[], int nlines); //done
void swap(char *v[], int i, int j); //done
void qsort(char *lineptr[], int left, int right); //done
int getline_custom(char s[], int lim); //done
char *alloc(int n); //done
int readlines(char *lineptr[], int maxlines); //done
int readlines_new(char *lineptr[], int maxlines, char out_array[][MAXLEN]);

int example() {
//    int nlines;
//
//    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
//        qsort(lineptr, 0, nlines - 1);
//        writelines(lineptr, nlines);
//        return 0;
//    } else {
//        printf("error: input too big to sort\n");
//        return 1;
//    }

    int nlines;

    char out_array[MAXLINES][MAXLEN];

    if ((nlines = readlines_new(lineptr, MAXLINES, out_array)) >= 0) {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

void writelines(char *lineptr[], int nlines) {
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

void swap(char *v[], int i, int j) {
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void qsort(char *v[], int left, int right) {
    int i, last;

    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

int getline_custom(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    } else
        return 0;
}

int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getline_custom(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
        return nlines;
}

int readlines_new(char *lineptr[], int maxlines, char out_array[][MAXLEN]) {
    int len, nlines;

    nlines = 0;
    while ((len = getline_custom(out_array[nlines], MAXLEN)) > 0)
        if (nlines >= maxlines)
            return -1;
        else {
            out_array[nlines][len - 1] = '\0';
            lineptr[nlines] = out_array[nlines];
            nlines++;
        }
        return nlines;
}

#endif //CODE_EXERCISE_5_7_H
