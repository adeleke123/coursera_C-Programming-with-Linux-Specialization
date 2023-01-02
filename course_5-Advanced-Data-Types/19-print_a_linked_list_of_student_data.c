#include <stdio.h>
#include <stdlib.h>

struct student {
      char name[50];
      int age;
      struct student *next;
};

struct student *createStudent(char studentName[], int studentAge);
void copyStr(char *source, char *target);
struct student * append(struct student * end, struct student * newStudptr);
void printStudents(struct student *start);

int main(void) {
    struct student *start, *newStudptr, *end, *tmp;
    int ageP, ageR, ageM;
    scanf("%d %d %d", &ageP, &ageR, &ageM);
    start = createStudent("Petra", ageP);
    end = start;
    newStudptr = createStudent("Remi", ageR);
    end = append(end, newStudptr);
    newStudptr = createStudent("Mike", ageM);
    end = append(end, newStudptr);
    printStudents(start);
    tmp = start->next;
    free(start);
    start = tmp;
    tmp = start->next;
    free(start);
    free(tmp);
    return 0;
}

struct student *createStudent(char studentName[], int studentAge) {
    struct student *ptr;
    ptr = (struct student *) malloc(sizeof(struct student));
    copyStr(studentName, ptr->name);
    ptr->age = studentAge;
    ptr->next = NULL;
    return ptr;
}

void copyStr(char *source, char *target) {
    int i = 0;
    while (source[i]!='\0') {
        target[i] = source[i];
        i++;
    }
    target[i] = '\0';
}

struct student * append(struct student * end, struct student * newStudptr) {
    end->next = newStudptr;
    return(end->next);
}

void printStudents(struct student *start) {
    struct student * ptr = start;
    while (ptr!=NULL) {
        printf("%s is %d years old.\n", ptr->name, ptr->age);
        ptr = ptr->next;
    }
}
/*
 Question 
 In this task you will continue working on the linked list of students in which you would like to store, for each student, their name and age. As before you are provided with some code that you should not modify:

A structure definition for the storage of each student's information.
A main() function to test your code.
Prototypes for the functions createStudent(), append() (from previous tasks) and printStudents() (from the current task).
You will need the function definitions (from previous tasks) for createStudent(), append() as well as any other functions you added, such as copyStr() for example. If you were unable to solve the previous task you have the option to be given the code for the append() function (see the quiz preceding this task) so that you can work on the current task.

Your new task is to write a function printStudents() which takes as input a pointer that holds the address of the start of a linked list of students. Your function should then print this list of students to the screen as specified in the example below. Your function should not return anything.

Program Explanation
This program is an example of how to create a linked list in C.

The first two lines are header file includes, which provide access to functions defined in the stdio and stdlib libraries.
The struct student definition creates a new data type called student, which has three fields: a character array called name, an integer called age, and a pointer to another student struct called next.
The createStudent function is defined to take in a character array (studentName) and an integer (studentAge) as arguments, and it returns a pointer to a student struct. It creates a new student struct and assigns the given studentName and studentAge to the appropriate fields in the struct. It also sets the next field to NULL.
The copyStr function is defined to take in two character arrays (source and target) and copies the contents of the source array into the target array. It does this by iterating through the source array and copying each element one by one until it reaches the NULL character.
The append function is defined to take in two pointers to student structs (end and newStudptr) and appends the newStudptr to the end of the linked list by setting the next field of the end struct to point to newStudptr. It then returns a pointer to the newStudptr.
The printStudents function is defined to take in a pointer to a student struct (start) and prints the name and age of each student in the linked list, starting at the start struct and following the next pointers until it reaches a struct with a NULL next field.
The main function reads in three integers (ageP, ageR, ageM) and creates three student structs using the createStudent function, passing in the appropriate name and age for each struct. It sets the start struct to the first struct, Petra, and the end struct to the last struct, Mike. It then calls the printStudents function to print the names and ages of all the students. Finally, it frees the memory used by each struct by first setting tmp to the second struct and freeing the memory used by the start struct, then setting start to tmp and freeing the memory used by the second struct, and finally freeing the memory used by the third struct.
*/
