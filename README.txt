PA1.c -- Ioannis Kyriazis

Loop Invariants:
1) c starts off at 0 and gets incremented by one every time
   if c is not equal to the starting day of the month. When
   c is equal to the starting day, the cursor is at the right
   position to start printing the days of the month

2) Since i picks up where start day leaves off, their sum is the
   position of the cursor on the calendar. When the position of
   the cursor on the calendar is divisible by 7, it is safe for
   the cursor to go on to the next line.

3) i is initialized with the number 1 and is continuosly
   incremented by one until it reaches the amount of days
   in the given month. Therefore we can conclude that i will
   always be the current month where January = 1, February = 2...

Summary:

The program prompts the user for a year. If the user 
enters an invalid year, the program prints 
an error message and exits. If their input is a valid year
then the calendar corresponding to the given year is printed.
The program works by impementing four functions. 

A function that
calculates the day of the week given the year, the day of the month,
and the month. The function uses an algorithm that was re-written
from https://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week.
The algorithm works by first checking to see
if the month is January or February. If it is, then the sum of the
previous year and the day is assigned to the day variable. If the
month is not January or February, then the sum of 2 years ago and
the day is assigned to the day variable. From then on the sum is
added to the month multiplied by (23/9). Then we add 4, the year 
divided by 4 and the year divided by 400. From that we subtract
the first two digits of the year and get a total. We divide that
total by 7 and take the remainder. The remainder is which day of
the week we calculated. Sunday being 0, Monday being 1, and so on.

A function that
prints the month's name using a switch statement. The function is 
given the year and the month and from that calculates how many days
in the given month. The function takes leap years into account when
it must return the total number of days for February.

A function that
prints the entire month.  The function starts by skipping through
the calendar until the cursor is at the first day of the month. 
From then on it prints the for loops counter, which starts at 1 and
ends at the number of days in the given month. Whenever the sum of
counter and the start day is divisible by 7 the cursor jumps to the
next line because that means that it reached the end of calender's
columns. This function returns the start day for the next month.

A function that
loops from 1 to 12 and prints out every month of the year.

The most trouble I had with this program was trying to get the cursor to
on to the next line at the right time. It took many trials and error until
I sat down and actually though the code through. I then realized that the
start day + the current day is the position of the cursor on the calendar
and when that is divisible by 7 go on to the next line.

*********** RUNNING THE PROGRAM *************

1) Go into the directory of where the PA1.c file is saved using the terminal

2) Type "gcc -Wall PA1.c" into the terminal and press enter 

3) Type "./a.out" into the terminal and press enter

