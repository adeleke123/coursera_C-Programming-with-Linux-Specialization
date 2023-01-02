#include <stdio.h>
#include <stdlib.h>

struct student {
      char name[50];
      int age;
      struct student *next;
};

struct student *createStudent(char studentName[], int studentAge);

// Write other function prototypes here (if any)

int main(void) {
    struct student *studptr;
    int myAge;
    char myName[50];
    scanf("%s %d", myName, &myAge);
    studptr = createStudent(myName, myAge);
    printf("New student created: %s is %d years old.\n", studptr->name, studptr->age);
    free(studptr);
    return 0;
}

// Write your createStudent function here (and any other functions you see fit)
struct student * createStudent(char studentName[], int studentAge)
{
    struct student * stuptr;
    stuptr = (struct student *) malloc(sizeof(struct student)); // added ; here
    int i = 0;
    while (studentName[i] != '\0')
    {
        stuptr->name[i] = studentName[i];
        i++;
    }
    stuptr->name[i] = '\0';
    stuptr->age = studentAge;
    stuptr->next = NULL;
    return stuptr;
}
/*

You would like to store student data (for each student, their name and age) in a linked list of students. You are given the following structure to store each student's information. Please do not modify this structure:

struct student {
      char name[50];
      int age;
      struct student *next;
};
Your first task is to write a function createStudent() that takes as inputs a string (namely a student's name) and an integer (their age) and that returns a pointer to a struct student which stores this information. Your function should dynamically allocate the memory required for this struct student and then write the student's name and age into this newly allocated memory. 

You are given the createStudent() function prototype and a main() function to test your code, please do not modify these:

struct student *createStudent(char studentName[], int studentAge);

int main(void) {
    struct student *studptr;
    int myAge;
    char myName[50];
    scanf("%s %d", myName, &myAge);
    studptr = createStudent(myName, myAge);
    printf("New student created: %s is %d years old.\n", studptr->name, studptr->age);
    free(studptr);
    return 0;
}
Examples
Input:
Petra 25
Output:
New student created: Petra is 25 years old.   
Input:
Remi 18
Output:
New student created: Remi is 18 years old.


Program Explanation

#include <stdio.h>

The first line of the code includes a header file called "stdio.h", which stands for Standard Input Output. This file contains functions for performing input and output operations in C.

#include <stdlib.h>

The second line includes another header file called "stdlib.h", which stands for Standard Library. This file contains functions for performing general functions in C, such as memory allocation and converting numbers to strings.

struct student {
char name[50];
int age;
struct student *next;
};

This is a struct definition for a struct called "student". A struct is a user-defined data type in C that can contain variables of different types. This struct has three fields: a char array called "name" with a size of 50, an integer called "age", and a struct pointer called "next" that points to another student struct.

struct student *createStudent(char studentName[], int studentAge);

This is a function prototype for a function called "createStudent", which takes in two arguments: a char array called "studentName" and an integer called "studentAge". The function returns a struct pointer to a student struct.

int main(void) {
struct student *studptr;
int myAge;
char myName[50];
scanf("%s %d", myName, &myAge);
studptr = createStudent(myName, myAge);
printf("New student created: %s is %d years old.\n", studptr->name, studptr->age);
free(studptr);
return 0;
}

This is the main function, which is the entry point of the program. It first declares a struct pointer called "studptr" and two variables: an integer called "myAge" and a char array called "myName" with a size of 50.

The function then uses the scanf function to read in a string and an integer from the user and store them in "myName" and "myAge" respectively.

The function then calls the "createStudent" function, passing in "myName" and "myAge" as arguments, and stores the returned struct pointer in "studptr".

The function then uses the printf function to print a string and the values of the "name" and "age" fields of the student struct pointed to by "studptr".

The function then frees the memory pointed to by "studptr" using the free function and returns 0 to indicate that the program has completed successfully.

struct student * createStudent(char studentName[], int studentAge)
{
struct student * stuptr;
stuptr = (struct student *) malloc(sizeof(struct student)); // added ; here
int i = 0;
while (studentName[i] != '\0')
{
stuptr->name[i] = studentName[i];
i++;
}
stuptr->name[i] = '\0';
stuptr->age = studentAge;
stuptr->next = NULL;
return stuptr;
}

This is the "createStudent" function that was prototyped earlier. It first declares a struct pointer called "stuptr".

The function then uses the malloc function to dynamically allocate memory for a student struct and stores the returned memory address in "stuptr".
*/

