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
struct digit * readNumber(void); 
struct digit * searchNumber(struct digit * start, int number);
struct digit * insertAtFront(struct digit * start, struct digit * newptr);
struct digit * reverseNumber(struct digit * start);
struct digit * sortedCopy(struct digit * start);
struct digit * insertIntoSorted(struct digit *start, struct digit *newDig);

int main(void) {
    //! showMemory(start=65520)
    struct digit *start, *backwards, *sorted;
    printf("Please enter a number: ");
    start = readNumber();
    printf("You entered: ");
    printNumber(start);
    printf("Backwards: ");
    backwards = reverseNumber(start);
    printNumber(backwards);
    printf("Sorted by digit:");
    sorted = sortedCopy(start);
    printNumber(sorted);
    freeNumber(start);
    freeNumber(backwards);
    freeNumber(sorted);
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

struct digit * searchNumber(struct digit * start, int number) {
    struct digit * ptr = start;
    while ((ptr!=NULL) && (ptr->num!=number)) {
        ptr = ptr->next;
    }
    return(ptr);
}

struct digit * insertAtFront(struct digit * start, struct digit * newptr) {
    newptr->next = start;
    return(newptr);
}

struct digit * reverseNumber(struct digit * start) {
    struct digit *ptr = start;
    struct digit *bstart = start;
    struct digit *newdigit;
    
    if (start!=NULL) {
        bstart = createDigit(start->num);
        ptr = ptr->next;
    }
    while (ptr != NULL) {
        newdigit = createDigit(ptr->num);
        bstart = insertAtFront(bstart, newdigit);
        ptr = ptr->next;
    }
    return(bstart);
}

struct digit * insertIntoSorted(struct digit *start, struct digit *newDig) {
    struct digit *ptr = start;
    struct digit *prev = NULL;
    while ((ptr!=NULL) && (ptr->num < newDig->num)) {
        prev = ptr;
        ptr = ptr->next;
    }
    if (prev == NULL) {
        start = insertAtFront(start, newDig);
    } else {
        prev->next = newDig;
        newDig->next = ptr;
    }
    return(start);
}

struct digit * sortedCopy(struct digit * start) {
    //! heap1=showMemory(start=348, cursors=[start, ptr, sortedStart, newDigit])
    //! heap2=showMemory(start=519, cursors=[start, newDigit, ptr, prev])
    struct digit *ptr = start;
    struct digit *sortedStart = NULL;
    struct digit *newDigit;
    
    if (start!=NULL) {
        sortedStart = createDigit(start->num);
        ptr = ptr->next;
    }
    while (ptr!=NULL) {
        newDigit = createDigit(ptr->num);
        sortedStart = insertIntoSorted(sortedStart, newDigit);
        ptr = ptr->next;
    }
    return(sortedStart);
}

/*
Program Explanation:

This program reads a number from the user, prints the number, prints the number backwards, and prints the digits in the number sorted from smallest to largest.

First, it includes two libraries, stdio.h and stdlib.h. stdio.h stands for Standard Input Output, and it contains functions for input and output, such as printf and scanf. stdlib.h stands for Standard Library, and it contains functions for memory management and conversions, among others.

Next, the program defines a structure called digit. This structure has two members: num which is an integer, and next which is a pointer to another digit structure.

Then, the program declares several functions. These functions will be defined later in the code.

After that, the main function is defined. This is the entry point of the program, and it will be the first function to be executed when the program runs. Inside the main function, several variables are declared: start, backwards, and sorted. These variables are pointers to digit structures.

The program then prompts the user to enter a number, and reads the number using the readNumber function. The readNumber function reads characters from the user, converts them to integers, and stores them in a linked list of digit structures. The linked list is created dynamically, meaning that memory is allocated for each element in the list as it is needed.

After the number is read, the program prints the number using the printNumber function. Then, it uses the reverseNumber function to reverse the digits of the number and stores the result in the backwards variable. The program then prints the reversed number.

Then, the program uses the sortedCopy function to create a copy of the number, sorted by digits, and stores the result in the sorted variable. Finally, the program prints the sorted number.

After that, the program frees the memory occupied by the three linked lists using the freeNumber function.

Finally, the main function returns 0, indicating that the program has terminated successfully.

After the main function, the previously declared functions are defined. The createDigit function creates a new digit structure with a given integer value and returns a pointer to it. The append function appends a new digit structure to the end of a linked list. The printNumber function prints a linked list of digit structures. The freeNumber function frees the memory occupied by a linked list of digit structures. The readNumber function reads a number from the user and stores it in a linked list of digit structures. The searchNumber function searches a linked list of digit structures for a given integer. The insertAtFront function inserts a new digit structure at the front of a linked list. The reverseNumber function reverses the order of the digits in a linked list. The sortedCopy function creates a copy of a linked list of digit structures, sorted by digits. And finally, the insertIntoSorted function inserts a new digit structure into a linked list, maintaining the order of the digits.
*/
