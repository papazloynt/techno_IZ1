#ifndef IZ1_DATE_H
#define IZ1_DATE_H

#include <stdbool.h>

typedef struct Date {
    int year;
    int month;
    int day_number;
} Date;

bool dateCompare(Date d1, Date d2);
void sortDates(Date* dates, const int size);
Date* fillingDates(const int size);
bool isCorrectDates(Date* dates, const int size);

#endif //IZ1_DATE_H
