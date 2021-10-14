// private headers
#include "date.h"
// c headers
#include <stdio.h>
#include <stdlib.h>

bool date_compare(date_t* d1, date_t* d2) {
  if (d1->year < d2->year) {
    return true;
  } else if (d1->year == d2->year && d1->month < d2->month) {
    return true;
  } else if (d1->year == d2->year && d1->month == d2->month &&
             d1->day_number < d2->day_number) {
    return true;
  }
  return false;
}

void sort_dates(date_t* dates, size_t size) {
  if (dates == NULL) {
    return;
  }

  for (int startIndex = 0; startIndex < size - 1; ++startIndex) {
    int smallestIndex = startIndex;

    for (int currentIndex = startIndex + 1; currentIndex < size;
         ++currentIndex) {
      if (date_compare(&dates[currentIndex], &dates[smallestIndex]))
        smallestIndex = currentIndex;
    }

    date_t tmp = dates[startIndex];
    dates[startIndex] = dates[smallestIndex];
    dates[smallestIndex] = tmp;
  }
}

date_t* filling_dates(size_t size) {
  // overflow values of size_t
  if (size > 1000000) {
    return NULL;
  }
  date_t* dates = (date_t*)malloc(size * sizeof(date_t));
  if (dates == NULL) return NULL;

  for (int i = 0; i < size; ++i) {
    int day_number, month, year;
    scanf("%d.%d.%d", &day_number, &month, &year);

    dates[i].day_number = day_number;
    dates[i].month = month;
    dates[i].year = year;
  }
  return dates;
}

bool is_correct_dates(date_t* dates, size_t size) {
  if (dates == NULL) {
    return false;
  }

  for (int i = 0; i < size; ++i) {
    if (dates[i].day_number > 31 || dates[i].day_number < 0 ||
        dates[i].month > 12 || dates[i].month < 0) {
      return false;
    }
  }
  return true;
}
