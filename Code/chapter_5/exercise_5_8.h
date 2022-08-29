
#ifndef CODE_EXERCISE_5_8_H
#define CODE_EXERCISE_5_8_H
// Problem Statement: There is no error checking in day_of_year or month_day. Remedy this defect.
static char daytab[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day) {
    if (month > 12 || month < 1)
        return -1;

    int i, leap;
    leap = year%4 == year%100 != 0 || year%400 == 0;

    if (day > daytab[leap][month] || day < 1)
        return -1;

    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

int month_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    if (yearday > 365 + leap || yearday < 1)
        return -1;

    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}

#endif //CODE_EXERCISE_5_8_H
