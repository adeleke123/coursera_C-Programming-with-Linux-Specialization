#include <stdio.h>
#include <stdlib.h>

struct digit {
    int num;
    struct digit *next;
};

struct digit * createDigit(int);
struct digit * append(struct digit * end, struct digit * newDigptr);
void printNumber(struct digit *);
void freeNumber(struct digit *start);
struct digit * readNumber();
struct digit * searchNumber(struct digit * start, int number);

int main(void) {
    //! stack = showMemory(start=65520)
    struct digit *start, *ptr;
    int searchNum = 5;
    printf("Please enter a number: ");
    start = readNumber();
    printNumber(start);
    ptr = searchNumber(start, searchNum);
    if (ptr!=NULL) {
        printf("Found digit %d at location %p.\n", searchNum, ptr);
    } else {
        printf("Digit %d not found.\n", searchNum);
    }
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

struct digit * readNumber() {
    //! heap=showMemory(start=309, cursors=[start, end, newptr])
    char c;
    int d;
    struct digit *start, *end, *newptr;
    start = NULL;
    scanf("%c", &c);
    while (c!='\n') {
        d = c - 48;
        newptr = createDigit(d);
        if (start==NULL) {
            start = newptr;
            end = start;
        } else {
            end = append(end, newptr);
        }
        scanf("%c", &c);
    }
    return start;
}

struct digit * searchNumber(struct digit * start, int number) {
//! heap=showMemory(start=348, cursors=[ptr,start])
    struct digit * ptr = start;
    while ((ptr!=NULL) && (ptr->num!=number)) {
        ptr = ptr->next;
    }
    return(ptr);
}
/*
This C program is a linked list implementation that reads in a number entered by the user, stores it as a linked list, and then searches the linked list for a specified digit. The number is entered by the user as an integer, but it is stored as a linked list, with each digit of the number being represented by a struct (a struct is a user-defined data type that can contain variables of different types). The struct for a digit has two members: an int called "num" which represents the digit itself, and a struct digit pointer called "next" which points to the next digit in the linked list.

Here is a breakdown of the code:

#include <stdio.h>
#include <stdlib.h>
These two lines are called "preprocessor directives" and they include two standard C libraries: stdio.h (standard input/output) and stdlib.h (standard library). These libraries contain functions that are used in the program.

struct digit {
    int num;
    struct digit *next;
};
This defines the struct for a digit. It has an int called "num" and a struct digit pointer called "next".

struct digit * createDigit(int);
struct digit * append(struct digit * end, struct digit * newDigptr);
void printNumber(struct digit *);
void freeNumber(struct digit *start);
struct digit * readNumber();
struct digit * searchNumber(struct digit * start, int number);
These are function prototypes. They tell the compiler what the function will return and what arguments it will take.

int main(void) {
    //! stack = showMemory(start=65520)
    struct digit *start, *ptr;
    int searchNum = 5;
    printf("Please enter a number: ");
    start = readNumber();
    printNumber(start);
    ptr = searchNumber(start, searchNum);
    if (ptr!=NULL) {
        printf("Found digit %d at location %p.\n", searchNum, ptr);
    } else {
        printf("Digit %d not found.\n", searchNum);
    }
    freeNumber(start);
    return 0;
}
This is the main function of the program. It declares two pointers to struct digit called "start" and "ptr" and an int called "searchNum" initialized to 5. It then prints a message asking the user to enter a number and calls the readNumber() function to get the number entered by the user, stored as a linked list. It then calls the printNumber() function to print the number. It then calls the searchNumber() function to search the linked list for the digit 5 and stores the result in "ptr". If "ptr" is not NULL (i.e. the digit was found), it prints a message saying that the digit was found and the location in memory where it was found. If "ptr" is NULL (i.e. the digit was not found), it prints a message saying that the digit was not found. Finally, it calls the freeNumber() function to free the memory used by the linked list.

struct digit *createDigit(int dig) {
    struct digit *ptr;
    ptr = (struct digit *) malloc(sizeof(struct digit));
    ptr->num = dig;
    ptr->next = NULL;
    return ptr;

This function creates a new digit struct and returns a pointer to it. It takes an int called "dig" as an argument, which represents the digit. It uses the malloc() function from the stdlib library to allocate memory for the struct and stores the address of the allocated memory in a struct digit pointer called "ptr". It then sets the "num" member of the struct to "dig" and the "next" member to NULL. It finally returns "ptr".

struct digit * append(struct digit * end, struct digit * newDigptr) {
    end->next = newDigptr;
    return(end->next);
}
This function adds a new digit to the end of a linked list and returns a pointer to the new end of the list. It takes two arguments: a struct digit pointer called "end" which points to the current end of the list, and a struct digit pointer called "newDigptr" which points to the new digit to be added. It sets the "next" member of the current end of the list to point to the new digit, and then returns a pointer to the new end of the list (the new digit).

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

struct digit * readNumber() {
    //! heap=showMemory(start=309, cursors=[start, end, newptr])
    char c;
    int d;
    struct digit *start, *end, *newptr;
    start = NULL;
    scanf("%c", &c);
    while (c!='\n') {
        d = c - 48;
        newptr = createDigit(d);
        if (start==NULL) {
            start = newptr;
            end = start;
       
This function reads in a number entered by the user and stores it as a linked list. It uses scanf() from the stdio library to get a character from the user and stores it in a char called "c". It then enters a while loop that continues until "c" is a newline character (i.e. the user has pressed enter). In each iteration of the loop, it converts the character "c" to an int by subtracting 48 (the ASCII value of '0') and stores the result in an int called "d". It then calls the createDigit() function to create a new digit struct and stores the address of the struct in a struct digit pointer called "newptr". If the linked list is empty (i.e. "start" is NULL), it sets "start" to "newptr" and "end" to "start". If the linked list is not empty, it calls the append() function to add the new digit to the end of the list and sets "end" to the new end of the list. Finally, it uses scanf() to get the next character from the user and stores it in "c". When the end of the input is reached (i.e. the user has pressed enter), it returns a pointer to the start of the linked list

struct digit * searchNumber(struct digit * start, int number) {
//! heap=showMemory(start=348, cursors=[ptr,start])
    struct digit * ptr = start;
    while ((ptr!=NULL) && (ptr->num!=number)) {
        ptr = ptr->next;
    }
    return(ptr);
}
This function searches a linked list for a specified digit and returns a pointer to the first occurrence of the digit in the list. If the digit is not found, it returns NULL. It takes two arguments: a pointer to the start of the linked list called "start" and an int called "number" which represents the digit to be searched for. It sets a pointer called "ptr" to the start of the list and then enters a while loop that continues until "ptr" is NULL or the "num" member of the current digit pointed to by "ptr" is equal to "number". In each iteration of the loop, it sets "ptr" to the next digit in the list. When the end of the list is reached or the digit is found, it returns a pointer to the current digit.
*/
