// PA1.c -- Ioannis Kyriazis
#include <stdio.h>

/**
* Using an algorithm found on wikipedia, this function calculates
* which day of the week it is, given the year, day, and month
* @param year the year
* @param day the day
* @param month the month
* @return The day of the week, where Sunday is 0.
*/
int calculateStartDay(int year, int day, int month) {
    // The algorithm that is being used to calculate the start day
    // was found on wikipedia. The algorithm being used is essentially
    // Michael Keith and Tom Craver's expression written in my own way.
    // https://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week
    // Sunday .. Saturday = 0..6

    int m; // will store a year according to following conditional
    if (month < 3) {
        // store previous year if month is before March
        m = year--;
    }
    else {
        // store year - 2 if month is after february
        m = year - 2;
    }
    day += m;
    return ((23 * month / 9) + day + 4 + (year / 4) 
            - (year / 100) + (year / 400)) % 7;

}

/**
* Prints the name of the given month in the given year 
* and calculates how many days in that month
* @param year the year of that the given month is in
* @param month the month that shall be printed January = 1
* @return The number of days in the given month of the given year
*/
int printMonthName(int year, int month) {

    // This function uses a switch statement to decide what to print
    // January is 1, February is 2 ...
    // The amount of days in a month is straightforward in every month
    // except February
    switch(month) {

        case 1 :
            printf("\nJanuary %d\n", year);
            return 31;
            break;
        
        case 2 :
            printf("\nFebruary %d\n", year);
            // years that are divisible by 4 are leap years, except that 
            // years divisible by 100 are not leap years unless they 
            // are also divisible by 400
            // the following conditionals express the above statement
            if ((year % 4 == 0) && (year % 100 == 0) && (year % 400 == 0)) {
                return 29;
            }
            else if ((year % 4 == 0) && (year % 100 == 0)) {
                return 28;
            }
            else if (year % 4 == 0) {
                return 29;
            }
            else {
                return 28;
            }
            break;

        case 3 :
            printf("\nMarch %d\n", year);
            return 31;
            break;

        case 4 :
            printf("\nApril %d\n", year);
            return 30;
            break;

        case 5 :
            printf("\nMay %d\n", year);
            return 31;
            break;
        
        case 6 :
            printf("\nJune %d\n", year);
            return 30;
            break;

        case 7 :
            printf("\nJuly %d\n", year);
            return 31;
            break;

        case 8 :
            printf("\nAugust %d\n", year);
            return 31;
            break;

        case 9 :
            printf("\nSeptember %d\n", year);
            return 30;
            break;
        
        case 10 :
            printf("\nOctober %d\n", year);
            return 31;
            break;

        case 11 :
            printf("\nNovember %d\n", year);
            return 30;
            break;

        case 12 :
            printf("\nDecember %d\n", year);
            return 31;
            break;

        default:
            return -1;
    }
}

/**
* Prints the entire month of the given year
* @param year the year of which month to print
* @param month the month to print
* @param startDay the day of the week in which the month starts
* @return the startDay of the next month
*/
int printMonth(int year, int month, int startDay) {
    int i, // loop's counter which represents days in the month
        c, // the cursor which will start at 0
        d; // the amount of days in the given month
    c = 0; // starts the cursor of the month printer at position 0

    // prints the month and sets d to the amount of days in the month
    d = printMonthName(year, month);

    //prints the days of the week
    printf("\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    // this loop moves the cursor to the day that the month starts
    // Pre condition: c is less than the start day
    while (c != startDay) {
        printf("     ");
        // INVARIANT 1:
        // c will be less than startDay until this loop finishes
        // when the loop finishes they will be equal
        c++;
    }
    // Post condition: c is equal to the start day

    // this loop prints the days in the month
    // i starts out as 1 and goes until the last day of the given month
    // Pre condition: No days have been printed since i == 1
    for (i = 1; i <= d; i++) {
        // INVARIANT 2:
        // i + startDay will always be the position of the cursor on
        // the calendar

        // if the position of the cursor has gone through a 
        // week continue printing
        // on the next line
        if ((i + startDay) % 7 == 0) {
            printf("%3d\n", i);
        }
        // otherwise put the days on the same line
        else {
            printf("%3d  ", i); 
        }
    }
    // Post condition: All days have been printed, 
    // since i == amount of days in month

    printf("\n");
    return (i + startDay - 1) % 7;
}

/**
* Goes through every month of the given year and 
* prints the months January through December
* @param year the year for which to print
* @param startDay the day of the week the given year starts on
*/
void printCalendar(int year, int startDay) {
    int i; // represents the current month being printed out

    // Pre condition: No months have been printed since i == 1
    for (i = 1; i < 13; i++) {
        // INVARIANT 3:
        // i will always correspond to the number of the month
        // that is being printed out
        startDay = printMonth(year, i, startDay);
    }
    // Post condition: All months have been printed because
    // i == 12
}

/**
* Prompts the user for the year they want the calendar for
* and then prints it. If the years is invalid the program
* tells the user
* @return 0 if the program runs successfully
*/
int main(void) {
    int year; // stores the integer that the user enters
    printf("\t\tMONTHLY CALENDAR\n\nPlease enter year for this calendar:- ");
    scanf("%d", &year);
    // if the user's input is invalid, inform them
    if (year <= 0) {
        printf("You entered %d, which is an invalid year.\n", year);
    }
    // otherwise run normally
    else {
        printf("\n\t*** Calendar for %d ***\n", year);
        printCalendar(year, calculateStartDay(year, 1, 1));
    }
    return 0;
}