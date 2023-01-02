#include <stdio.h>
#include <stdlib.h>

struct digit {
    int num;
    struct digit *next;
};

struct digit * createDigit(int);
struct digit * append(struct digit * end, struct digit * newDigptr);
void printNumber(struct digit *);
void freeNumber(struct digit *);
struct digit *readNumber(void); 
int divisibleByThree(struct digit * start);

int main(void) {
    struct digit *start;
    start = readNumber();
    printf("The number ");
    printNumber(start);
    if (divisibleByThree(start)) 
        printf("is divisible by 3.\n");
    else
        printf("is not divisible by 3.\n");
    freeNumber(start);
    return 0;
}

struct digit *createDigit(int dig) {
    struct digit *ptr;
    ptr = (struct digit *) malloc(sizeof(struct digit));
    ptr->num = dig;
    ptr->next = NULL;
    return ptr;
}

struct digit * append(struct digit * end, struct digit * newDigptr) {
    end->next = newDigptr;
    return(end->next);
}

void printNumber(struct digit *start) {
    struct digit * ptr = start;
    while (ptr!=NULL) {
        printf("%d", ptr->num);
        ptr = ptr->next;
    }
    printf("\n");
}

void freeNumber(struct digit *start) {
    struct digit * ptr = start;
    struct digit * tmp;
    while (ptr!=NULL) {
        tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}

struct digit *readNumber(void) {
    char c;
    int d;
    struct digit *start, *end, *newptr;
    start = NULL;
    scanf("%c", &c);
    while (c != '\n') {
        d = c-48;
        newptr = createDigit(d);
        if (start == NULL) {
            start = newptr;
            end = start;
        } else {
            end = append(end, newptr);
        }
        scanf("%c", &c);
    }
    return(start);
}

int divisibleByThree(struct digit * start) {
    struct digit * ptr = start;
    int qsum = 0;
    while (ptr!=NULL) {
        qsum += ptr->num;
        ptr = ptr->next;
    }
    if (qsum%3==0) return 1;
    else return 0;
}

/*
Program Explanation:

This C program is checking if a number is divisible by 3. The number is entered by the user as an integer, but it is stored as a linked list, with each digit of the number being represented by a struct (a struct is a user-defined data type that can contain variables of different types). The struct for a digit has two members: an int called "num" which represents the digit itself, and a struct digit pointer called "next" which points to the next digit in the linked list.

Here is a breakdown of the code:

#include <stdio.h>
#include <stdlib.h>
These two lines are called "preprocessor directives" and they include two standard C libraries: stdio.h (standard input/output) and stdlib.h (standard library). These libraries contain functions that are used in the program.

struct digit {
    int num;
    struct digit *next;
};
This defines the struct for a digit. It has an int called "num" and a struct digit pointer called "next".

Copy code
struct digit * createDigit(int);
struct digit * append(struct digit * end, struct digit * newDigptr);
void printNumber(struct digit *);
void freeNumber(struct digit *);
struct digit *readNumber(void);
int divisibleByThree(struct digit * start);
These are function prototypes. They tell the compiler what the function will return and what arguments it will take.

int main(void) {
    struct digit *start;
    start = readNumber();
    printf("The number ");
    printNumber(start);
    if (divisibleByThree(start))
        printf("is divisible by 3.\n");
    else
        printf("is not divisible by 3.\n");
    freeNumber(start);
    return 0;
}
This is the main function of the program. It calls the readNumber() function to get the number entered by the user, stored as a linked list. It then calls the printNumber() function to print the number. It then calls the divisibleByThree() function to determine if the number is divisible by 3. If it is, it prints a message saying that it is divisible by 3. If it is not, it prints a message saying that it is not. Finally, it calls the freeNumber() function to free the memory used by the linked list.

struct digit *createDigit(int dig) {
    struct digit *ptr;
    ptr = (struct digit *) malloc(sizeof(struct digit));
    ptr->num = dig;
    ptr->next = NULL;
    return ptr;
}
This function creates a new digit for the linked list. It takes an int as an argument (the digit itself) and returns a pointer to the new digit. It uses the malloc() function to allocate memory for the new digit and initializes the "num" member to the digit passed as an argument and the "next" member to NULL.

struct digit * append(struct digit * end, struct digit * newDigptr) {
    end->next = newDigptr;
    return(end->next);
}
This function adds a new digit to the end of the linked list. It takes two arguments: a pointer to the current end of the list and a pointer to the new digit to be added. It sets the "next" member of the current end of the list to point to the new digit, and then returns a pointer to the new end of the list (the new digit).

void printNumber(struct digit *start) {
    struct digit * ptr = start;
    while (ptr!=NULL) {
        printf("%d", ptr->num);
        ptr = ptr->next;
    }
    printf("\n");
}
This function prints the number represented by the linked list. It takes a pointer to the start of the list as an argument. It sets a pointer called "ptr" to the start of the list and then enters a while loop that continues until "ptr" is NULL (i.e. the end of the list has been reached). In each iteration of the loop, it prints the "num" member of the current digit pointed to by "ptr" and then sets "ptr" to the next digit in the list. When the end of the list is reached, it prints a newline character.

void freeNumber(struct digit *start) {
    struct digit * ptr = start;
    struct digit * tmp;
    while (ptr!=NULL) {
        tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}
This function frees the memory used by the linked list. It takes a pointer to the start of the list as an argument. It sets a pointer called "ptr" to the start of the list and another pointer called "tmp" to NULL. It then enters a while loop that continues until "ptr" is NULL. In each iteration of the loop, it sets "tmp" to the next digit in the list, frees the memory used by the current digit pointed to by "ptr", and then sets "ptr" to the value of "tmp". This effectively frees all of the memory used by the linked list.

struct digit *readNumber(void) {
    char c;
    int d;
    struct digit *start, *end, *newptr;
    start = NULL;
    scanf("%c", &c);
    while (c != '\n') {
        d = c-48;
        newptr = createDigit(d);
        if (start == NULL) {
            start = newptr;
            end = start;
        } else {
            end = append(end, newptr);
        }
        scanf("%c", &c);
    }
    return(start);
}
This function reads in a number entered by the user and stores it as a linked list. It does not take any arguments. It reads in a character at a time and converts it to an int. It then creates a new digit for the int using the createDigit() function. If the linked list is empty (i.e. this is the first digit being added), it sets the "start" and "end" pointers to the new digit. If the linked list is not empty, it adds the new digit to the end of the list using the append() function and updates the "end" pointer. It continues reading in characters and adding digits to the list until it reads a newline character. It then returns a pointer to the start of the list.

int divisibleByThree(struct digit * start) {
    struct digit * ptr = start;

This function determines if a number represented by a linked list is divisible by 3. It takes a pointer to the start of the linked list as an argument. It sets a pointer called "ptr" to the start of the list and an int called "qsum" to 0. It then enters a while loop that continues until "ptr" is NULL (i.e. the end of the list has been reached). In each iteration of the loop, it adds the "num" member of the current digit pointed to by "ptr" to "qsum" and then sets "ptr" to the next digit in the list. When the end of the list is reached, it checks if "qsum" is divisible by 3. If it is, it returns 1 (true). If it is not, it returns 0 (false).

Question:

In this task you will work with the linked list of digits we have created in the lessons up to this point. As before you are provided with some code that you should not modify:

A structure definition for the storage of each digit's information.
A main() function to test your code.
The functions createDigit(), append(), printNumber(), freeNumber() and readNumber() which we have written in the lectures.
Your task is to write a new function divisibleByThree() which takes as input a pointer that holds the address of the start of a linked list of digits. Your function should then check whether the number stored in this linked list of digits is divisible by three. The function should return the value 1 if indeed the number is divisible by three and it should return the value 0 otherwise.
*/
