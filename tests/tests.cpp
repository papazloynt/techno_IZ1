#include "gtest/gtest.h"

extern "C" {
#include "date.h"
#include <malloc.h>
}

TEST(date, wrong_size) {
    ASSERT_EQ(fillingDates(-1), nullptr);
}

TEST(date, wrong_dates) {
    const int size = 3;
    const int wrong_number = 40;

    Date* dates = (Date*)malloc(size * sizeof(Date));
    if (dates == NULL) FAIL();

    for (size_t i = 0; i < size; ++i) {
        dates[i].day_number = wrong_number;
        dates[i].month = wrong_number;
        dates[i].year = 2021;
    }
    EXPECT_EQ(isCorrectDates(dates, size), false);

    free(dates);
}

TEST(date, check_sort) {
    const int size = 3;

    Date* dates = (Date*)malloc(size * sizeof(Date));
    if (dates == NULL) FAIL();

    dates[0].day_number = 31;
    dates[0].month = 10;
    dates[0].year = 2000;

    dates[1].day_number = 2;
    dates[1].month = 11;
    dates[1].year = 2021;

    dates[2].day_number = 2;
    dates[2].month = 10;
    dates[2].year = 2000;

    EXPECT_EQ(isCorrectDates(dates, size), true);

    sortDates(dates, size);

    EXPECT_EQ(dates[0].day_number, 2);
    EXPECT_EQ(dates[0].month, 10);
    EXPECT_EQ(dates[0].year, 2000);

    EXPECT_EQ(dates[1].day_number, 31);
    EXPECT_EQ(dates[1].month, 10);
    EXPECT_EQ(dates[1].year, 2000);

    EXPECT_EQ(dates[2].day_number, 2);
    EXPECT_EQ(dates[2].month, 11);
    EXPECT_EQ(dates[2].year, 2021);

    free(dates);
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}