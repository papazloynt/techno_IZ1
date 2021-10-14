// private headers
#include "date.h"
// c++ headers
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    printf("Input number of dates:\n");

    int size;
    scanf("%d", &size);

    Date* dates = fillingDates(size);
    // check input
    if (!isCorrectDates(dates, size)) {
        free(dates);
        return 1;
    }

    sortDates(dates, size);

    printf("Sorted Dates:\n");
    for (int i = 0; i < size; ++i) {
        printf("%d.%d.%d\n", dates[i].day_number, dates[i].month, dates[i].year);
    }
    free(dates);
    return 0;
}