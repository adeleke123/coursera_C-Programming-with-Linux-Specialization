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
void freeStudents(struct student *start);

int main(void) {
    struct student *start, *newStudptr, *end;
    int ageP, ageR, ageM;
    scanf("%d %d %d", &ageP, &ageR, &ageM);
    start = createStudent("Petra", ageP);
    end = start;
    newStudptr = createStudent("Remi", ageR);
    end = append(end, newStudptr);
    newStudptr = createStudent("Mike", ageM);
    end = append(end, newStudptr);
    printStudents(start);
    freeStudents(start);
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

void freeStudents(struct student *start) {
    struct student * ptr = start;
    struct student * tmp;
    while (ptr!=NULL) {
        tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}
/*
In this task you will continue working on the linked list of students in which you would like to store, for each student, their name and age. As before you are provided with some code that you should not modify:

A structure definition for the storage of each student's information.
A main() function to test your code. 
Prototypes for the functions createStudent(), append(), printStudents (from previous tasks) and freeStudents() (from the current task).
You will need the function definitions (from previous tasks) for createStudent(), append(), printStudents() as well as any other functions you added, such as copyStr() for example. If you were unable to solve the previous task you have the option to be given the code for the printStudents() function (see the quiz preceding this task) so that you can work on the current task.

Your current task is to write a function freeStudents() which takes as input a pointer that holds the address of the start of a linked list of students. Your function should then free the space allocated for each student in this list of students. Your function should not return anything.

Program Explanation

This code is a program that creates a linked list data structure to store a series of students as records. Each student record contains a name and an age. The program reads in three ages from the user and then creates three student records using these ages and predefined names "Petra", "Remi", and "Mike". It then performs some operations on the linked list, such as adding new students to the end of the list, printing the students in the list, and freeing the memory used by the list.

Here is a line-by-line explanation of the code:

#include <stdio.h>
#include <stdlib.h>
These lines include two C standard library header files: stdio.h and stdlib.h. The stdio.h header provides functions for input and output, such as scanf, which is used later in the code to read in the student ages from the user, and printf, which is used later in the code to print the student records. The stdlib.h header provides functions for memory allocation and conversion, such as malloc, which is used later in the code to allocate memory for new student records in the linked list.

struct student {
      char name[50];
      int age;
      struct student *next;
};
This defines a new data type called struct student, which represents a single student record in the linked list. It has three fields: name, which is an array of characters representing the student's name, age, which is an integer representing the student's age, and next, which is a pointer to the next struct student in the list.

struct student *createStudent(char studentName[], int studentAge);
void copyStr(char *source, char *target);
struct student * append(struct student * end, struct student * newStudptr);
void printStudents(struct student *start);
void freeStudents(struct student *start);
These lines declare five function prototypes. A function prototype specifies the return type and arguments of a function, but not the function body. The first function, createStudent, returns a pointer to a struct student and takes two arguments: a character array called studentName and an integer called studentAge. The second function, copyStr, returns void (i.e., no value) and takes two arguments: a pointer to a character called source and a pointer to a character called target. The third function, append, returns a pointer to a struct student and takes two arguments: a pointer to a struct student called end and a pointer to a struct student called newStudptr. The fourth function, printStudents, returns void and takes a pointer to a struct student called start as an argument. The fifth function, freeStudents, returns void and takes a pointer to a struct student called start as an argument.

int main(void) {
    struct student *start, *newStudptr, *end;
    int ageP, ageR, ageM;
    scanf("%d %d %d", &ageP, &ageR, &ageM);
    start = createStudent("Petra", ageP);
    end = start;
    newStudptr = createStudent("Remi", ageR);
    end = append(end, newStudptr);
    newStudptr = createStudent("Mike", ageM);
    end = append(end, newStudptr);
    printStudents(start);
    freeStudents(start);
    return 0;
}


This is the main function of the program, which is where execution starts. It declares three variables: `start`, `newStudptr`, and `end`, all of which are pointers to `struct student`. It also declares three integer variables: `ageP`, `ageR`, and `ageM`, which will be used to store the ages read in from the user.

The `scanf` function is called to read in three integers from the user and store them in `ageP`, `ageR`, and `ageM`, respectively. The `createStudent` function is then called to create a new student record with the name "Petra" and the age of `ageP`, and the returned pointer is assigned to `start`. `end` is then set to `start`. `newStudptr` is then set to the result of calling `createStudent` with the name "Remi" and the age of `ageR`. The `append` function is then called with `end` and `newStudptr` as arguments, and the returned pointer is assigned to `end`. This adds the new student record to the end of the linked list.

The process is repeated to add the student record with the name "Mike" and the age of `ageM` to the end of the list. The `printStudents` function is then called with `start` as an argument, which prints the student records in the linked list. Finally, the `freeStudents` function is called with `start` as an argument, which frees the memory used by the linked list. The `main` function then returns 0 to indicate that the program has completed successfully.

struct student *createStudent(char studentName[], int studentAge) {
struct student *ptr;
ptr = (struct student *) malloc(sizeof(struct student));
copyStr(studentName, ptr->name);
ptr->age = studentAge;
ptr->next = NULL;
return ptr;
}


This function takes two arguments: a character array called `studentName` and an integer called `studentAge`. It creates a new `struct student` with the name of `studentName` and the age of `studentAge`, and a `next` field set to `NULL`. It then returns a pointer to the new `struct student`.

void copyStr(char *source, char *target) {
int i = 0;
while (source[i]!='\0') {
target[i] = source[i];
i++;
}
target[i] = '\0';
}


This function takes two arguments: a pointer to a character called `source` and a pointer to a character called `target`.
It defines an integer variable i and initializes it to 0. It then enters a loop that iterates as long as the i-th element of source is not the null character. Inside the loop, it sets the i-th element of target to the i-th element of source and increments i. When the loop completes, it sets the i-th element of target to the null character, which terminates the string. This function is used to copy the string stored in source to the string stored in target.

struct student * append(struct student * end, struct student * newStudptr) {
    end->next = newStudptr;
    return(end->next);
}
This function takes two arguments: a pointer to a struct student called end and a pointer to a struct student called newStudptr. It sets the next field of end to newStudptr, which adds the new student record to the end of the linked list. It then returns a pointer to the new student record.

void printStudents(struct student *start) {
    struct student * ptr = start;
    while (ptr!=NULL) {
        printf("%s is %d years old.\n", ptr->name, ptr->age);
        ptr = ptr->next;
    }
}
This function takes a single argument: a pointer to a struct student called start. It defines a pointer called ptr and initializes it to start. It then enters a loop that iterates as long as ptr is not NULL. Inside the loop, it prints the name and age of the student record pointed to by ptr and then sets ptr to the value of ptr->next. This causes the loop to move to the next student record in the linked list. When the loop completes, it has printed all of the student records in the linked list.

void freeStudents(struct student *start) {
    struct student * ptr = start;
    struct student * tmp;
    while (ptr!=NULL) {
        tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}
This function takes a single argument: a pointer to a struct student called start. It defines two pointers: ptr and tmp. It initializes ptr to start and enters a loop that iterates as long as ptr is not NULL. Inside the loop, it sets tmp to the value of ptr->next, frees the memory pointed to by ptr, and then sets ptr to the value of tmp. This causes the loop to move to the next student record in the linked list and free its memory. When the loop completes, all of the memory used by the linked list has been freed.
*/
