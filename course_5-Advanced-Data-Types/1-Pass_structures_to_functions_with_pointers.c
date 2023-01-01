#include <stdio.h>

struct student{
	char firstName[30];
	char lastName[30];
	int birthYear;
	double aveGrade;
};
void printStudent(struct student);
void readStudent(struct student *studptr);
int main(void) {
   //! showMemory(start=65520)
    struct student me;
    readStudent(&me);
    printStudent(me);
	return 0;
}

void readStudent(struct student *studptr) {
    printf("\nEnter a new student record: \n");
    printf("First name: ");
    scanf("%s", (*studptr).firstName);
    printf("Last name: ");
    scanf("%s", (*studptr).lastName);
    printf("Birth year: ");
    scanf("%d", &(*studptr).birthYear);
    printf("Average grade: ");
    scanf("%lf", &(*studptr).aveGrade);
}

void printStudent(struct student stud) {
    printf("Name: %s %s\n", stud.firstName, stud.lastName);
	printf("Year of birth: %d\n",stud.birthYear);
	printf("Average grade: %.2lf\n",stud.aveGrade);
}

This code defines a struct (short for structure) called student which has four fields: `firstName`, `lastName`, `birthYear`, and `aveGrade`.

The struct is used to represent a student record. firstName and lastName are both character arrays (strings) of length 30, birthYear is an integer, and aveGrade is a double-precision floating point number.

The code also defines three functions: printStudent, readStudent, and main.

The printStudent function takes a single struct student as an argument and prints the values of its fields.

The readStudent function takes a pointer to a struct student as an argument and reads values for each of its fields from the user. It uses the scanf function to read the values entered by the user into the appropriate fields of the struct.

The main function is the entry point of the program. It creates a struct student variable called me and calls the readStudent function, passing the address of me as an argument. This allows the readStudent function to modify the fields of me. The main function then calls the printStudent function, passing me as an argument, to print the student record.




