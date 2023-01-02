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
    printf("%s is %d years old.\n", start->name, start->age);
    printf("%s is %d years old.\n", start->next->name, start->next->age);
    printf("%s is %d years old.\n", start->next->next->name, start->next->next->age);
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

/*
Program Explanation
#include <stdio.h>

This line includes the header file "stdio.h", which stands for Standard Input Output. This file contains functions for performing input and output operations in C.

#include <stdlib.h>

This line includes the header file "stdlib.h", which stands for Standard Library. This file contains functions for performing general functions in C, such as memory allocation and converting numbers to strings.

struct student {
char name[50];
int age;
struct student *next;
};

This is a struct definition for a struct called "student". A struct is a user-defined data type in C that can contain variables of different types. This struct has three fields: a char array called "name" with a size of 50, an integer called "age", and a struct pointer called "next" that points to another student struct.

struct student *createStudent(char studentName[], int studentAge);

This is a function prototype for a function called "createStudent", which takes in two arguments: a char array called "studentName" and an integer called "studentAge". The function returns a struct pointer to a student struct.

void copyStr(char *source, char *target);

This is a function prototype for a function called "copyStr", which takes in two arguments: a char pointer called "source" and a char pointer called "target". The function does not return any value.

struct student * append(struct student * end, struct student * newStudptr);

This is a function prototype for a function called "append", which takes in two arguments: a struct pointer called "end" and a struct pointer called "newStudptr". The function returns a struct pointer to a student struct.

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
printf("%s is %d years old.\n", start->name, start->age);
printf("%s is %d years old.\n", start->next->name, start->next->age);
printf("%s is %d years old.\n", start->next->next->name, start->next->next->age);
tmp = start->next;
free(start);
start = tmp;
tmp = start->next;
free(start);
free(tmp);
return 0;
}

This is the main function, which is the entry point of the program. It first declares four struct pointers: "start", "newStudptr", "end", and "tmp". It then declares three integers: "ageP", "ageR", and "ageM".

The function then uses the scanf function to read in three integers from the user and stores them in "ageP", "ageR", and "ageM" respectively.

The function then calls the "createStudent" function, passing in "Petra" and "ageP" as arguments, and stores the returned struct pointer in "start". It then sets "end" to "start".

The function then calls the "createStudent" function, passing in "Remi" and "ageR" as arguments, and stores the returned struct pointer in "newStudptr". It then calls the "append" function, passing in "end" and "newStudptr" as arguments, and stores the returned struct pointer in "end".

The function then calls the "createStudent" function, passing in "Mike" and "ageM" as arguments, and stores the returned struct pointer in "newStudptr". It then calls the "append" function, passing in "end" and "newStudptr" as arguments, and stores the returned struct pointer in "end".

The function then uses the printf function to print the name and age of the first, second, and third student in the linked list.

The function then uses the "tmp" pointer to store the next student struct in the linked list, frees the memory pointed to by "start", and sets "start" to "tmp". It then repeats this process to free the memory pointed to by "start" and "tmp". Finally, the function returns 0 to indicate that the program has completed successfully.

struct student *createStudent(char studentName[], int studentAge) {
struct student *ptr;
ptr = (struct student *) malloc(sizeof(struct student));
copyStr(studentName, ptr->name);
ptr->age = studentAge;
ptr->next = NULL;
return ptr;
}

This is the "createStudent" function that was prototyped earlier. It takes in two arguments: a char array called "studentName" and an integer called "studentAge".

The function dynamically allocates memory for a student struct using the malloc function and stores the returned memory address in "ptr". It then calls the "copyStr" function, passing in "studentName" and "ptr->name" as arguments, to copy the string in "studentName" to the "name" field of the student struct pointed to by "ptr". It then sets the "age" field of the student struct to "studentAge" and the "next" field to NULL. It then returns "ptr".

void copyStr(char *source, char *target) {
int i = 0;
while (source[i]!='\0') {
target[i] = source[i];
i++;
}
target[i] = '\0';
}

This is the "copyStr" function that was prototyped earlier. It takes in two arguments: a char pointer called "source" and a char pointer called "target".

The function copies the string in "source" to "target" one character at a time until it reaches the null character '\0' in "source". It then adds a null character '\0' to the end of "target" to mark the end of the string.

struct student * append(struct student * end, struct student * newStudptr) {
end->next = newStudptr;
return(end->next);
}

This is the "append" function that was prototyped earlier. It takes in two arguments: a struct pointer called "end" and a struct pointer called "newStudptr".

The function sets the "next" field of the student struct pointed to by "end" to "newStudptr" and then returns "end->next".

Question

In this task you will continue working on the linked list of students in which you would like to store, for each student, their name and age. As before you are provided with some code that you should not modify:

A structure definition for the storage of each student's information.
A main() function to test your code.
Prototypes for the functions createStudent() (from the previous task) and append() (from the current task).
You will need the function definition (from the previous task) for createStudent(), as well as any other functions you added, such as copyStr() for example. If you were unable to solve the previous task you have the option to be given the code for the createStudent() function (see the quiz preceding this task) so that you can work on the current task.

Your new task is to write a function append() which takes as input two pointers: the first pointer holds the address of the current end of the linked list of students, the second pointer points to a newly created student. Your function should append this new student to the linked list and return the address (a struct student *) of the new end of the list.
*/
