#ifndef IZ1_DATE_H
#define IZ1_DATE_H

#include <stdbool.h>

typedef struct date_t {
    int year;
    int month;
    int day_number;
} date_t;

bool date_compare(const date_t d1, const date_t d2);
void sort_dates(date_t* dates, const int size);
date_t* filling_dates(const int size);
bool is_correct_dates(date_t* dates, const int size);

#endif //IZ1_DATE_H
