#include <stdio.h>

struct student{
	char firstName[5];
	char lastName[5];
	int birthYear;
	double aveGrade;
};

int main(void) {
    //! showMemory(start=65520)
	struct student me;
    printf("Size of struct student is %zu.\n", sizeof(struct student));
    printf("Size of firstName is %zu.\n", sizeof(me.firstName));
    printf("Size of lastName is %zu.\n", sizeof(me.lastName));
    printf("Size of birthYear is %zu.\n", sizeof(me.birthYear));
    printf("Size of aveGrade is %zu.\n", sizeof(me.aveGrade));

	return 0;
}

/*
#include <stdio.h>: This line includes the header file stdio.h in the program. This header file contains declarations for input and output functions, such as printf, which are used later in the code.

struct student{...};: This line defines a struct (short for structure) called student with four fields: firstName, lastName, birthYear, and aveGrade. firstName and lastName are character arrays (strings) of length 5, birthYear is an integer, and aveGrade is a double-precision floating point number.

int main(void) {...}: This line defines the main function, which is the entry point of the program. The main function returns an int (integer) value and takes no arguments (void). The code inside the curly braces {...} is the body of the main function.

struct student me;: This line creates a variable of type struct student called me.

printf("Size of struct student is %zu.\n", sizeof(struct student));: This line prints the size of the struct student type in bytes. The sizeof operator returns the size of its operand in bytes. The %zu format specifier tells printf to print the size as an unsigned integer. The \n character causes a new line to be printed.

printf("Size of firstName is %zu.\n", sizeof(me.firstName));: This line prints the size of the firstName field of the me variable in bytes. The sizeof operator returns the size of its operand in bytes. The %zu format specifier tells printf to print the size as an unsigned integer. The \n character causes a new line to be printed.

printf("Size of lastName is %zu.\n", sizeof(me.lastName));: This line prints the size of the lastName field of the me variable in bytes. The sizeof operator returns the size of its operand in bytes. The %zu format specifier tells printf to print the size as an unsigned integer. The \n character causes a new line to be printed.

printf("Size of birthYear is %zu.\n", sizeof(me.birthYear));: This line prints the size of the birthYear field of the me variable in bytes. The sizeof operator returns the size of its operand in bytes. The %zu format specifier tells printf to print the size as an unsigned integer. The \n character causes a new line to be printed.

printf("Size of aveGrade is %zu.\n", sizeof(me.aveGrade));: This line prints the size of the aveGrade field of the me variable in bytes. The sizeof operator returns the size of its operand in bytes. The %zu format specifier tells printf to print the size as an unsigned integer. The \n character causes a new line to be printed.

return 0;: This line causes the main function to return the value 0 to the operating system.
*/
