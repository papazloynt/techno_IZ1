#ifndef IZ1_DATE_H
#define IZ1_DATE_H

#include <stdbool.h>
#include <stddef.h>

typedef struct date_t {
  int year;
  int month;
  int day_number;
} date_t;

bool date_compare(date_t* d1, date_t* d2);
void sort_dates(date_t* dates, size_t size);
date_t* filling_dates(size_t size);
bool is_correct_dates(date_t* dates, size_t size);

#endif  // IZ1_DATE_H
