#include <stdio.h>

struct student{
	char firstName[30];
	char lastName[30];
	int birthYear;
	double aveGrade;
};
void printStudent(struct student stud);
int main(void) {
	//! showMemory(start=65520)
	struct student me={"Petra", "Bonfert-Taylor", 1989, 3.5};
	struct student you={"Remi", "Sharrock", 2005, 3.5};
	
	printStudent(me);
	printStudent(you);
	return 0;
}

void printStudent(struct student stud){
    printf("Name: %s %s\n", stud.firstName, stud.lastName);
	printf("Year of birth: %d\n",stud.birthYear);
	printf("Average grade: %.2lf\n",stud.aveGrade);
}

/*
This code defines a struct (short for structure) called student which has four fields: firstName, lastName, birthYear, and aveGrade.

The struct is used to represent a student record. firstName and lastName are both character arrays (strings) of length 30, birthYear is an integer, and aveGrade is a double-precision floating point number.

The code also defines two functions: printStudent and main.

The printStudent function takes a single struct student as an argument and prints the values of its fields.

The main function is the entry point of the program. It creates two variables of type struct student: me and you. It initializes the fields of these variables to the specified values. It then calls the printStudent function twice, passing me and you as arguments, to print the student records.
*/
