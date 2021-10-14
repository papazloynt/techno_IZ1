// private headers
#include "date.h"
// c++ headers
#include <stdio.h>
#include <stdlib.h>

bool dateCompare(Date d1, Date d2) {
    if (d1.year < d2.year) {
        return true;
    } else if (d1.year == d2.year &&
               d1.month < d2.month ) {
        return true;
    } else if (d1.year == d2.year &&
               d1.month == d2.month &&
               d1.day_number < d2.day_number) {
        return true;
    }
    return false;
}

void sortDates(Date* dates, const int size) {
    for (int startIndex = 0; startIndex < size - 1; ++startIndex) {
        int smallestIndex = startIndex;

        for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex) {
            if (dateCompare(dates[currentIndex], dates[smallestIndex]))
                smallestIndex = currentIndex;
        }

        Date tmp = dates[startIndex];
        dates[startIndex] = dates[smallestIndex];
        dates[smallestIndex] = tmp;
    }
}

Date* fillingDates(const int size) {
    if (size < 0 ) {
        return NULL;
    }
    Date* dates = (Date*)malloc(size * sizeof(Date));
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

bool isCorrectDates(Date* dates, const int size) {
    for (int i = 0; i < size; ++i) {
        if (dates[i].day_number > 31 || dates[i].day_number < 0
                || dates[i].month > 12 || dates[i].month < 0) {
            return false;
        }
    }
    return true;
}
