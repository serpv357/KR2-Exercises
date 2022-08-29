
#ifndef CODE_EXERCISE_5_9_H
#define CODE_EXERCISE_5_9_H
// Problem Statement: Rewrite the routines day_of_year and month_day with pointers instead of indexing.

#include <printf.h>

static char daytab[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day) {
    if (month > 12 || month < 1)
        return -1;

    int i, leap;
    leap = year%4 == year%100 != 0 || year%400 == 0;

    char (*p)[2] = *(daytab + leap);

    if (day > *(*p + month)  || day < 1)
        return -1;

    for (i = 1; i < month; i++)
        day += *(*p + i);
    return day;
}

int month_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    if (yearday > 365 + leap || yearday < 1)
        return -1;

    char (*p)[2] = *(daytab + leap);

    for (i = 1; yearday > *(*p + i); i++)
        yearday -= *(*p + i);
    *pmonth = i;
    *pday = yearday;
}

void example() {
    int month = 3;
    int day = 27;
    int year = 2001;

    int dayOfYear = day_of_year(year, month, day);
    printf("day of year: %d\n", dayOfYear);

    int yearday = 112;

    month_day(year, yearday, &month, &day);
    printf("month and day: %d %d", month, day);

}

#endif //CODE_EXERCISE_5_9_H
