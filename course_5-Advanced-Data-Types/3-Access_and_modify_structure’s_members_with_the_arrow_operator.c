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
    scanf("%s", studptr->firstName);
    printf("Last name: ");
    scanf("%s", studptr->lastName);
    printf("Birth year: ");
    scanf("%d", &studptr->birthYear);
    printf("Average grade: ");
    scanf("%lf", &studptr->aveGrade);
}

void printStudent(struct student stud) {
    printf("Name: %s %s\n", stud.firstName, stud.lastName);
	printf("Year of birth: %d\n",stud.birthYear);
	printf("Average grade: %.2lf\n",stud.aveGrade);
}
/*
#include <stdio.h>: This line includes the header file stdio.h in the program. This header file contains declarations for input and output functions, such as printf and scanf, which are used later in the code.

struct student{...};: This line defines a struct (short for structure) called student with four fields: firstName, lastName, birthYear, and aveGrade. firstName and lastName are character arrays (strings) of length 30, birthYear is an integer, and aveGrade is a double-precision floating point number.

void printStudent(struct student);: This line declares a function called printStudent that takes a single argument of type struct student and returns no value (void). The function is not defined yet; its implementation is given later in the code.

void readStudent(struct student *studptr);: This line declares a function called readStudent that takes a single argument: a pointer to a struct student. The function returns no value (void). The function is not defined yet; its implementation is given later in the code.

int main(void) {...}: This line defines the main function, which is the entry point of the program. The main function returns an int (integer) value and takes no arguments (void). The code inside the curly braces {...} is the body of the main function.

struct student me;: This line creates a variable of type struct student called me.

readStudent(&me);: This line calls the readStudent function and passes the address of me as an argument. This allows the readStudent function to modify the fields of me.

printStudent(me);: This line calls the printStudent function and passes me as an argument.

return 0;: This line causes the main function to return the value 0 to the operating system.

void readStudent(struct student *studptr) {...}: This line defines the readStudent function. The code inside the curly braces {...} is the body of the function. The function takes a single argument: a pointer to a struct student.

printf("\nEnter a new student record: \n");: This line prints the string "\nEnter a new student record: \n" to the console. The \n characters cause a new line to be printed.

printf("First name: ");: This line prints the string "First name: " to the console.

scanf("%s", studptr->firstName);: This line reads a string from the console and stores it in the firstName field of the struct pointed to by studptr.

printf("Last name: ");: This line prints the string "Last name: " to the console.

scanf("%s", studptr->lastName);: This line reads a string from the console and stores it in the lastName field of the struct pointed to by studptr.

printf("Birth year: ");: This line prints the string "Birth year: " to the console.

scanf("%d", &studptr->birthYear);: This line reads an integer from the console and stores it in the birthYear field of the struct pointed to by studptr.

printf("Average grade: ");: This line prints the string "Average grade: " to the console.

scanf("%lf", &studptr->aveGrade);: This line reads a double-precision floating point number from the console and stores it in the aveGrade field of the struct pointed to by studptr.

void printStudent(struct student stud) {...}: This line defines the printStudent function. The code inside the curly braces {...} is the body of the function. The function takes a single argument of type struct student called stud.

printf("Name: %s %s\n", stud.firstName, stud.lastName);: This line prints the values of the firstName and lastName fields of the stud argument, separated by a space. The \n character causes a new line to be printed.

printf("Year of birth: %d\n",stud.birthYear);: This line prints the value of the birthYear field of the stud argument. The \n character causes a new line to be printed.

printf("Average grade: %.2lf\n",stud.aveGrade);: This line prints the value of the aveGrade field of the stud argument. The %.2lf format specifier tells printf to print the value as a floating point number with two decimal places. The \n character causes a new line to be printed.
*/
