#include <stdio.h>
#include <stdlib.h>

struct digit
{
    int num;
    struct digit *next;
};

struct digit * createDigit(int);
struct digit * append(struct digit * end, struct digit * newDigptr);
void printNumber(struct digit *);
void freeNumber(struct digit *);
struct digit * readNumber(void); 
struct digit * searchNumber(struct digit * start, int number);
struct digit * insertAtFront(struct digit * start, struct digit * newptr);
struct digit * insertIntoSorted(struct digit *start, struct digit *newDig);
struct digit * sortedCopy(struct digit *);
int countRedun(struct digit * start);

int main(void) {
    struct digit *start;
    start = readNumber();
    printf("The number ");
    printNumber(start);
    printf("contains %d redundancies.\n", countRedun(start));
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

struct digit * readNumber(void) {
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

struct digit * insertAtFront(struct digit * start, struct digit * newptr) {
    newptr->next = start;
    return(newptr);
}

struct digit * insertIntoSorted(struct digit *start, struct digit *newDig){
    struct digit * ptr = start;
    struct digit * prev = NULL;
    while ((ptr!=NULL) && (ptr->num < newDig->num)) {
        prev = ptr;
        ptr = ptr->next;
    }
    if (prev==NULL) {
        start = insertAtFront(start, newDig);
    } else {
        prev->next = newDig;
        newDig->next = ptr;
    }
    return(start);
}

struct digit * sortedCopy(struct digit * start){
    struct digit *ptr = start;
    struct digit *sortedStart=NULL;
    struct digit *newDigit;

    if (start!=NULL) {
        sortedStart = createDigit(start->num);
        ptr = start->next;
    }
    while (ptr != NULL) {
        newDigit = createDigit(ptr->num);
        sortedStart = insertIntoSorted(sortedStart, newDigit);
        ptr = ptr->next;
    }
    return(sortedStart);
}

int countRedun(struct digit * start) {
    struct digit *sorted = sortedCopy(start);
    struct digit *ptr = sorted;
    int redun = 0;
    int prev = -1;
    
    while (ptr != NULL) {
        if (ptr->num == prev) 
            redun++;
        else 
            prev = ptr->num;
        ptr = ptr->next;
    }
    freeNumber(sorted);
    return redun;
}
/*
Question:

In this task you will again work with the linked list of digits we created during the lessons up to this point.

You are provided with (but are not required to use) the functions and prototypes we have written so far. You are also provided with a main() function to test your code. Please do not modify this main() function.

Your task is to write a new function countRedun() which takes as input a pointer that holds the address of the start of a linked list of digits. Your function should count how many redundancies can be observed in the number stored in this list and return this count of redundancies. A redundancy is a digit which has previously already occurred in the number. For example, in the number 39534, the second '3' is a redundancy.

Program Explanation:
The code is written in the C programming language and is intended to accept a number from the user, store it as a linked list (a data structure in which each element, called a "node," stores a value and a pointer to the next node in the list), and then count the number of "redundancies" in the number.

Here is an explanation of the code, line by line:

#include <stdio.h>
#include <stdlib.h>
These lines include two libraries in the code. stdio.h stands for "standard input/output" and contains functions for performing input and output operations in C. stdlib.h stands for "standard library" and contains functions for general purpose functions, such as memory allocation, random number generation, and converting strings to numbers.

struct digit
{
    int num;
    struct digit *next;
};
This code defines a structure called "digit" that has two members: an integer called "num" and a pointer to a struct digit called "next." This structure will be used to create a linked list of digits.

struct digit * createDigit(int);
struct digit * append(struct digit * end, struct digit * newDigptr);
void printNumber(struct digit *);
void freeNumber(struct digit *);
struct digit * readNumber(void);
struct digit * searchNumber(struct digit * start, int number);
struct digit * insertAtFront(struct digit * start, struct digit * newptr);
struct digit * insertIntoSorted(struct digit *start, struct digit *newDig);
struct digit * sortedCopy(struct digit *);
int countRedun(struct digit * start);
These lines declare functions that are defined later in the code. The function names are self-explanatory:

createDigit creates a new digit node
append appends a new digit node to the end of a list
printNumber prints out the digits in a list
freeNumber frees the memory used by a list
readNumber reads in a number from the user and stores it as a list
searchNumber searches a list for a specific digit
insertAtFront inserts a new digit node at the front of a list
insertIntoSorted inserts a new digit node into a list in sorted order
sortedCopy creates a sorted copy of a list
countRedun counts the number of redundancies in a list


int main(void) {
    struct digit *start;
    start = readNumber();
    printf("The number ");
    printNumber(start);
    printf("contains %d redundancies.\n", countRedun(start));
    freeNumber(start);
    return 0;
}
This is the main function of the program. It declares a pointer to a digit called start and assigns it the value returned by readNumber. It then prints out the number and the number of redundancies, and frees the memory used by the list.

The rest of the code defines the functions that were declared earlier.

struct digit *createDigit(int dig) {
    struct digit *ptr;
    ptr = (struct digit *) malloc(sizeof(struct digit));
    ptr->num = dig;
    ptr->next = NULL;
    return ptr;
}
This function takes an integer dig as input and creates a new digit node with the value of dig. It then returns a pointer to the new node.

struct digit * append(struct digit * end, struct digit * newDigptr) {
    end->next = newDigptr;
    return(end->next);
}
This function takes two pointers to digit nodes, end and newDigptr, as input. It appends newDigptr to the end of the list by updating the next pointer of end to point to newDigptr. It then returns a pointer to newDigptr.

void printNumber(struct digit *start) {
    struct digit * ptr = start;
    while (ptr!=NULL) {
        printf("%d", ptr->num);
        ptr = ptr->next;
    }
    printf("\n");
}
This function takes a pointer to a digit node called start as input and prints out the digits in the list starting from start. It does this by iterating through the list with a while loop and using the printf function to print out each digit.

void freeNumber(struct digit *start) {
    struct digit * ptr = start;
    struct digit * tmp;
    while (ptr!=NULL) {
        tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}
This function takes a pointer to a digit node called start as input and frees the memory used by the list starting from start. It does this by iterating through the list with a while loop and using the free function to free each node.

struct digit * readNumber(void) {
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
This function reads in a number from the user as a character string and stores it as a linked list. It does this by using the scanf function to read in a character at a time, converting it to an integer with the d = c-48 line (since the ASCII value of the character '0' is 48), creating a new digit node with this integer value, and appending it to the end of the list. It returns a pointer to the start of the list.

struct digit * insertAtFront(struct digit * start, struct digit * newptr) {
    newptr->next = start;
    return(newptr);
}
This function takes two pointers to digit nodes, start and newptr, as input and inserts newptr at the front of the list. It does this by updating the next pointer of newptr to point to start, and then returning a pointer to newptr.

struct digit * insertIntoSorted(struct digit *start, struct digit *newDig){
    struct digit * ptr = start;
    struct digit * prev = NULL;
    while ((ptr!=NULL) && (ptr->num < newDig->num)) {
        prev = ptr;
        ptr = ptr->next;
    }
    if (prev==NULL) {
        start = insertAtFront(start, newDig);
    } else {
        prev->next = newDig;
        newDig->next = ptr;
    }
    return(start);
}
This function takes two pointers to digit nodes, start and newDig, as input and inserts newDig into a sorted list such that the resulting list is also sorted. It does this by iterating through the list with a while loop and keeping track of the previous node with the prev pointer. If prev is NULL, it means that newDig should be inserted at the front of the list. If prev is not NULL, it inserts newDig between prev and the current node ptr. It returns a pointer to the start of the list.

struct digit * sortedCopy(struct digit * start){
    struct digit *ptr = start;
    struct digit *sortedStart=NULL;
    struct digit *newDigit;

    if (start!=NULL) {
        sortedStart = createDigit(start->num);
        ptr = start->next;
    }
    while (ptr != NULL) {
        newDigit = createDigit(ptr->num);
        sortedStart = insertIntoSorted(sortedStart, newDigit);
        ptr = ptr->next;
    }
    return(sortedStart);
}
This function takes a pointer to a digit node called start as input and creates a sorted copy of the list starting from start. It does this by iterating through the list with a while loop, creating a new digit node with the value of the current node, and inserting it into a sorted list using the insertIntoSorted function. It returns a pointer to the start of the sorted list.

int countRedun(struct digit * start) {
    struct digit *sorted = sortedCopy(start);
    struct digit *ptr = sorted;
    int redun = 0;
    int prev = -1;

    while (ptr != NULL) {
        if (ptr->num == prev)
            redun++;
        else
            prev = ptr->num;
        ptr = ptr->next;
    }
    freeNumber(sorted);
    return redun;
}
This function takes a pointer to a digit node called start as input and counts the number of redundancies in the list starting from start. It does this by first creating a sorted copy of the list using the sortedCopy function, and then iterating through the sorted list with a while loop. It keeps track of the previous digit with the prev variable and increments the redun counter every time it encounters a redundancy (i.e., when the current digit is equal to the previous one). Finally, it frees the memory used by the sorted list and returns the count of redundancies.
*/
