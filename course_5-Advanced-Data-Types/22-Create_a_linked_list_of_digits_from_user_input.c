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

int main(void) {
    //! stack = showMemory(start=65520)
    struct digit *start;
    printf("Please enter a number: ");
    start = readNumber();
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
/*
Program Explanation:
This code is a program that creates a linked list data structure to store a series of digits as records. Each digit record contains an integer representing the digit. The program has functions to create new digit records, add digit records to the end of the linked list, print the digits in the list, and free the memory used by the list. It also has a function called readNumber that reads in a sequence of digits from the user and creates a linked list to store them.

Here is a line-by-line explanation of the code:

#include <stdio.h>
#include <stdlib.h>
These lines include the standard input/output and standard library header files, which provide functions for performing input and output and for performing general-purpose tasks such as dynamic memory allocation.

struct digit {
    int num;
    struct digit *next;
};
This defines a structure type called struct digit that has two fields: an integer called num and a pointer to a struct digit called next.

struct digit * createDigit(int);
struct digit * append(struct digit * end, struct digit * newDigptr);
void printNumber(struct digit *);
void freeNumber(struct digit *start);
struct digit * readNumber();
These lines declare the functions that are used in the program. The createDigit function creates a new digit record, the append function adds a digit record to the end of the linked list, the printNumber function prints the digits in the list, the freeNumber function frees the memory used by the list, and the readNumber function reads in a sequence of digits from the user and creates a linked list to store them

int main(void) {
    //! stack = showMemory(start=65520)
    struct digit *start;
    printf("Please enter a number: ");
    start = readNumber();
    printNumber(start);
    freeNumber(start);
    return 0;
}
This is the main function of the program. It declares a pointer to a struct digit called start and initializes it to NULL. It then prints a prompt asking the user to enter a number, calls the readNumber function to read in the number and create a linked list to store it, and stores the pointer to the start of the linked list in start. It then calls the printNumber function to print the digits in the list and the freeNumber function to free the memory used by the list. Finally, it returns 0 to indicate that the program has completed successfully.

struct digit *createDigit(int dig) {
    struct digit *ptr;
    ptr = (struct digit *) malloc(sizeof(struct digit));
    ptr->num = dig;
    ptr->next = NULL;
    return ptr;
}
This function takes a single argument: an integer called dig. It creates a new struct digit with the num field set to dig and the next field set to NULL. It then returns a pointer to the new struct digit.

struct digit * append(struct digit * end, struct digit * newDigptr) {
    end->next = newDigptr;
    return(end->next);
}
This function takes two arguments: pointers to struct digit called end and newDigptr. It sets the next field of the struct digit pointed to by end to newDigptr, and then returns the value of the next field of the struct digit pointed to by end.

The next field of a struct digit is a pointer to the next digit record in the linked list. By setting the next field of the struct digit pointed to by end to newDigptr, this function adds the digit record pointed to by newDigptr to the end of the linked list.

The return value of the function is the value of the next field of the struct digit pointed to by end, which is now equal to newDigptr. This allows the calling function to update the variable that stores the end of the linked list with the new end of the linked list, which is now the digit record pointed to by newDigptr.

void printNumber(struct digit *start) {
    struct digit * ptr = start;
    while (ptr!=NULL) {
        printf("%d", ptr->num);
        ptr = ptr->next;
    }
    printf("\n");
}
This function takes a single argument: a pointer to a struct digit called start. It declares a pointer to a struct digit called ptr and initializes it to start. It then enters a loop that continues until ptr is NULL. Inside the loop, it prints the value of the num field of the struct digit pointed to by ptr, and then sets ptr to the value of the next field of the struct digit pointed to by ptr. This causes the loop to iterate through the linked list, printing the num field of each struct digit. When the loop completes, it prints a newline character.

void freeNumber(struct digit *start) {
    struct digit * ptr = start;
    struct digit * tmp;
    while (ptr!=NULL) {
        tmp = ptr->next;
	free(ptr);
        ptr = tmp;
    }
}
This function takes a single argument: a pointer to a struct digit called start. It declares two pointers to struct digit called ptr and tmp. It initializes ptr to start and enters a loop that continues until ptr is NULL. Inside the loop, it sets tmp to the value of the next field of the struct digit pointed to by ptr, calls the free function to free the memory used by the struct digit pointed to by ptr, and then sets ptr to tmp. This causes the loop to iterate through the linked list, freeing the memory used by each struct digit.

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
This function reads in a sequence of digits from the user and creates a linked list to store them. It declares three pointers to struct digit called start, end, and newptr, and initializes start to NULL. It then reads in a single character from the user into the variable c using the scanf function. It enters a loop that continues until c is a newline character. Inside the loop, it converts the character c to an integer by subtracting 48 from its ASCII value, creates a new digit record using the createDigit function, and stores the pointer to the new digit record in newptr. It then checks if start is NULL. If it is, it sets start to newptr and end to start. Otherwise, it calls the append function to add the new digit record to the end of the linked list and sets end to the return value of the append function. Finally, it reads in the next character from the user into c using scanf. When the loop completes, it returns start, which is a pointer to the start of the linked list.
*/
