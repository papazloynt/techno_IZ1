// private headers
#include "date.h"
// c headers
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  printf("Input number of dates:\n");

  int size;
  scanf("%d", &size);

  date_t* dates = filling_dates((size_t)size);
  // check input
  if (!is_correct_dates(dates, (size_t)size)) {
    free(dates);
    return 1;
  }

  sort_dates(dates, size);

  printf("Sorted Dates:\n");
  for (int i = 0; i < size; ++i) {
    printf("%d.%d.%d\n", dates[i].day_number, dates[i].month, dates[i].year);
  }
  free(dates);

  return 0;
}
