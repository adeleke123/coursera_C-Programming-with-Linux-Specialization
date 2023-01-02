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

int main(void) {
    //! stack = showMemory(start=65520)
    struct digit *start, *newDigptr, *end, *tmp;
    int first = 5;
    int second = 3;
    int third = 7;
    start = createDigit(first);
    end = start;
    newDigptr = createDigit(second);
    end = append(end, newDigptr);
    newDigptr = createDigit(third);
    end = append(end, newDigptr);
    printNumber(start);
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
    //! heap=showMemory(start=277, cursors=[ptr,start,tmp])
    struct digit * ptr = start;
    struct digit * tmp;
    while (ptr!=NULL) {
        tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}
/*
Program Explanation

This code is a program that creates a linked list data structure to store a series of digits as integers. It then performs some operations on the linked list, such as adding new digits to the end of the list, printing the digits in the list, and freeing the memory used by the list.

Here is a line-by-line explanation of the code:

#include <stdio.h>
#include <stdlib.h>

These lines include two C standard library header files: stdio.h and stdlib.h. The stdio.h header provides functions for input and output, such as printf, which is used later in the code to print the digits in the linked list. The stdlib.h header provides functions for memory allocation and conversion, such as malloc, which is used later in the code to allocate memory for new digits in the linked list.

struct digit {
    int num;
    struct digit *next;
};
This defines a new data type called struct digit, which represents a single digit in the linked list. It has two fields: num, which is an integer representing the digit, and next, which is a pointer to the next struct digit in the list.

struct digit * createDigit(int);
struct digit * append(struct digit * end, struct digit * newDigptr);
void printNumber(struct digit *);
void freeNumber(struct digit *start);
These lines declare four function prototypes. A function prototype specifies the return type and arguments of a function, but not the function body. The first function, createDigit, returns a pointer to a struct digit and takes an integer argument. The second function, append, returns a pointer to a struct digit and takes two arguments: a pointer to a struct digit and a pointer to a struct digit. The third function, printNumber, returns void (i.e., no value) and takes a pointer to a struct digit as an argument. The fourth function, freeNumber, returns void and takes a pointer to a struct digit as an argument.

int main(void) {
    struct digit *start, *newDigptr, *end, *tmp;
    int first = 5;
    int second = 3;
    int third = 7;
    start = createDigit(first);
    end = start;
    newDigptr = createDigit(second);
    end = append(end, newDigptr);
    newDigptr = createDigit(third);
    end = append(end, newDigptr);
    printNumber(start);
    freeNumber(start);
    return 0;
}
This is the main function of the program, which is where execution starts. It declares four variables: start, newDigptr, end, and tmp, all of which are pointers to struct digit. It then defines three integer variables: first, second, and third, which are set to the values 5, 3, and 7, respectively.

The createDigit function is called to create a new digit with the value of first and assign the returned pointer to start. end is then set to start. newDigptr is then set to the result of calling createDigit with the value of second. The append function is then called with end and newDigptr as arguments, and the returned pointer is assigned to end. This adds the new digit with the value of second to the end of the linked list.

The process is repeated to add the digit with the value of third to the end of the list. The printNumber function is then called with start as an argument, which prints the digits in the linked list. Finally, the freeNumber function is called with start as an argument, which frees the memory used by the linked list. The main function then returns 0 to indicate that the program has completed successfully.

struct digit *createDigit(int dig) {
    struct digit *ptr;
    ptr = (struct digit *) malloc(sizeof(struct digit));
    ptr->num = dig;
    ptr->next = NULL;
    return ptr;
}
This function takes an integer argument dig and creates a new struct digit with the value of dig and a next field set to NULL. It then returns a pointer to the new struct digit.

struct digit * append(struct digit * end, struct digit * newDigptr) {
    end->next = newDigptr;
    return(end->next);
}
This function takes two arguments: a pointer to a struct digit called end and a pointer to a struct digit called newDigptr. It sets the next field of end to newDigptr, which adds the new digit to the end of the linked list. It then returns a pointer to the new digit.

void printNumber(struct digit *start) {
    struct digit * ptr = start;
    while (ptr!=NULL) {
        printf("%d", ptr->num);
        ptr = ptr->next;
    }
    printf("\n");
}
This function takes a single argument: a pointer to a struct digit called start. It defines a pointer called ptr and initializes it to start. It then enters a loop that iterates as long as ptr is not NULL. Inside the loop, it prints the value of ptr->num and then sets ptr to the value of ptr->next. This causes the loop to move to the next digit in the linked list. When the loop completes, it prints a newline character.

void freeNumber(struct digit *start) {
    struct digit * ptr = start;
    struct digit * tmp;
    while (ptr!=NULL) {
        tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}
This function takes a single argument: a pointer to a struct digit called start. It defines two pointers: ptr and tmp. It initializes ptr to start and enters a loop that iterates as long as ptr is not NULL. Inside the loop, it sets tmp to the value of ptr->next, frees the memory pointed to by ptr, and then sets ptr to the value of tmp. This causes the loop to move to the next digit in the linked list and free its memory. When the loop completes, all of the memory used by the linked list has been freed.
*/
