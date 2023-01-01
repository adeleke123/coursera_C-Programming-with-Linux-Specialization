#include <stdio.h>

struct date {
        int year;
        int month;
        int day;
    };

/* function prototypes */
void printDate(struct date);
void readDate(struct date *);
struct date advanceDay(struct date); 

int main(void) {
	struct date today, tomorrow;
	readDate(&today);
	printDate(today);
	tomorrow = advanceDay(today);
	printDate(tomorrow);
	return 0;
}

/* function definitions */
void readDate(struct date *nowptr) {
    scanf("%d%d%d", &((*nowptr).year), &((*nowptr).month), &((*nowptr).day));
}

void printDate(struct date now) {
    printf("%02d/%02d/%4d\n", now.month, now.day, now.year);
}

struct date advanceDay(struct date today) {
    int d = today.day;
    int m = today.month;
    int y = today.year;
    int days;
    struct date tomorrow;
    if ((m==1) || (m==3) || (m==5) || (m==7) || (m==8) || (m==10) || (m==12)) {
        days = 31;
    } else if (m==2) {
        if (y%4==0) {
            if (y%100 == 0) {
                if (y%400 ==0) {
                    days = 29;
                } else {
                    days = 28;
                }
            } else {
                days = 29;
            }
        } else {
            days = 28;
        }
    } else {
        days = 30;
    }
    if (d<days) d++;
    else {
        d=1;
        if (m==12) {
            m = 1;
            y++;
        } else m++;
    }
    tomorrow.year = y;
    tomorrow.month = m;
    tomorrow.day = d;
    return(tomorrow);
}
/*
Question
In this problem you will continue developing the data feature which you started implementing in the previous problem.
You will implement a "tomorrow" feature in the C programming language via a function called "advanceDay()".
The function advanceDay() should take as input a date (stored in a struct date) and return the date of the following day.
You do not have to take into account leap years (although you may if you wish to).
That is, it is okay for your function to always return March 1 as the day following February 28, no matter the year.
You are provided with a familiar date structure definition, a main function as well as the function prototypes for the readDate(),
printDate(), and advanceDate() functions. Do not modify any of the given code.
Simply add your function definitions underneath the main() function.
For the readDate() and printDate() functions you may simply copy and paste the code you developed in the previous task.

Program Explaination

This C program defines a struct called date that represents a calendar date with fields for the year, month, and day. It has three functions:

readDate: This function reads in a date from the user and stores it in a date struct. It takes a pointer to a date struct as input and uses the scanf function to read in the values for the year, month, and day.

printDate: This function takes a date struct as input and prints it to the screen in the format "mm/dd/yyyy". It uses the printf function to format the output.

advanceDay: This function takes a date struct as input and returns a new date struct representing the following day. It first determines the number of days in the current month based on the month and year fields of the input date struct. It then increments the day field and checks if it has exceeded the number of days in the month. If it has, the function sets the day field to 1 and increments the month field. Finally, it checks if the month field has exceeded 12 and, if it has, increments the year field and sets the month field to 1.

The main function first reads in a date from the user using the readDate function and stores it in a date struct called today. It then prints the today struct using the printDate function. It then calls the advanceDay function with today as input and stores the returned value in a date struct called tomorrow. Finally, it prints the tomorrow struct using the printDate function.

*/

