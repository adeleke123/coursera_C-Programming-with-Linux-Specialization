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
struct digit * reverseNumber(struct digit * start);
struct digit * insertAtFront(struct digit * start, struct digit * newptr); 

int main(void) {
    //! stack = showMemory(start=65520)
    struct digit *start, *ptr, *backwards;
    printf("Please enter a number: ");
    start = readNumber();
    printNumber(start);
    backwards = reverseNumber(start);
    printNumber(backwards);
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

struct digit * insertAtFront(struct digit * start, struct digit * newptr) {
    //! heap=showMemory(start=348, cursors=[newptr,start])
    newptr->next = start;
    return(newptr);
}

struct digit * reverseNumber(struct digit * start) {
    //! heap=showMemory(start=336, cursors=[ptr,start,bstart,newdigit])
    struct digit *ptr = start;
    struct digit *bstart = NULL;
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
/* 
Program Explanation

This program prompts the user to enter a number and then does the following:

It reads the number from the user input and stores it in a linked list data structure, where each digit of the number is represented by a node in the linked list.

It prints the original number.

It reverses the number by iterating through the linked list and creating a new linked list with the digits in the reverse order.

It prints the reversed number.

It frees the memory used by the original linked list.

Let's go through the code line by line:

#include <stdio.h>
#include <stdlib.h>
These lines include the standard input/output and standard library header files in the program. These header files contain functions for performing input/output operations and functions for performing various tasks such as memory allocation, etc.

struct digit {
    int num;
    struct digit *next;
};
This defines a struct (structure) called digit which has two members: an integer called num and a pointer to a digit struct called next. A struct is a user-defined data type that can contain variables of different types. The digit struct is used to represent a digit in the linked list.

struct digit * createDigit(int);
struct digit * append(struct digit * end, struct digit * newDigptr);
void printNumber(struct digit *);
void freeNumber(struct digit *start);
struct digit * readNumber();
struct digit * searchNumber(struct digit * start, int number);
struct digit * reverseNumber(struct digit * start);
struct digit * insertAtFront(struct digit * start, struct digit * newptr);
These lines declare functions that will be used in the program. A function declaration tells the compiler about a function's name, return type, and parameters.

int main(void) {
    //! stack = showMemory(start=65520)
    struct digit *start, *ptr, *backwards;
    printf("Please enter a number: ");
    start = readNumber();
    printNumber(start);
    backwards = reverseNumber(start);
    printNumber(backwards);
    freeNumber(start);
    return 0;
}
This is the main function where the program starts execution. It declares three variables of type struct digit *: start, ptr, and backwards. start will point to the head of the linked list of the original number, backwards will point to the head of the linked list of the reversed number, and ptr will be used as an iterator for traversing the linked list.

The program prompts the user to enter a number and then calls the readNumber function to read the number and store it in a linked list. It then prints the original number using the printNumber function and reverses the number by calling the reverseNumber function. It prints the reversed number and then frees the memory used by the original linked list using the freeNumber function.

struct digit *createDigit(int dig) {
    struct digit *ptr;
    ptr = (struct digit *) malloc(sizeof(struct digit));
    ptr->num = dig;
    ptr->next = NULL;
    return ptr;
}

This function creates a new node in the linked list to store a digit. It takes an integer dig as a parameter, which is the digit to be stored in the node. It allocates memory for the node using the malloc function and assigns the value of dig to the num member of the node. It sets the next member to NULL to indicate that this is the last node in the linked list. Finally, it returns a pointer to the new node.

struct digit * append(struct digit * end, struct digit * newDigptr) {
    end->next = newDigptr;
    return(end->next);
}
This function appends a new node to the end of the linked list. It takes two parameters: a pointer to the current end of the linked list called end and a pointer to the new node called newDigptr. It sets the next member of the current end node to point to the new node and then returns a pointer to the new node.

void printNumber(struct digit *start) {
    struct digit * ptr = start;
    while (ptr!=NULL) {
        printf("%d", ptr->num);
        ptr = ptr->next;
    }
    printf("\n");
}
This function prints the number stored in the linked list. It takes a pointer to the head of the linked list called start as a parameter. It declares a pointer called ptr and initializes it with start. It then iterates through the linked list using a while loop and prints the value of the num member of each node. When it reaches the end of the linked list, it prints a newline character.

void freeNumber(struct digit *start) {
    struct digit * ptr = start;
    struct digit * tmp;
    while (ptr!=NULL) {
        tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}
This function frees the memory used by the linked list. It takes a pointer to the head of the linked list called start as a parameter. It declares two pointers called ptr and tmp and initializes ptr with start. It then iterates through the linked list using a while loop and frees the memory used by each node using the free function. It stores the value of the next member of the current node in tmp before freeing the current node so that it can move to the next node in the next iteration.

struct digit * readNumber() {
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
This function reads the number from the user input and stores it in a linked list. It reads each character of the input using the scanf function and converts it to an integer by subtracting 48 ( the ASCII value of the character '0'). It then creates a new node using the createDigit function to store the digit. If this is the first node being created, it sets the start and end pointers to point to the new node. Otherwise, it appends the new node to the end of the linked list using the append function and updates the end pointer. It continues reading characters and creating nodes until it encounters a newline character. Finally, it returns a pointer to the head of the linked list.

struct digit * searchNumber(struct digit * start, int number) {
    //! heap=showMemory(start=348, cursors=[ptr,start])
    struct digit * ptr = start;
    while ((ptr!=NULL) && (ptr->num!=number)) {
        ptr = ptr->next;
    }
    return(ptr);
}
This function searches the linked list for a given number. It takes two parameters: a pointer to the head of the linked list called start and the number to be searched called number. It declares a pointer called ptr and initializes it with start. It then iterates through the linked list using a while loop and checks if the num member of each node is equal to number. If it finds a match, it returns a pointer to the node. If it reaches the end of the linked list without finding a match, it returns NULL.

struct digit * insertAtFront(struct digit * start, struct digit * newptr) {
    //! heap=showMemory(start=348, cursors=[newptr,start])
    newptr->next = start;
    return(newptr);
}
This function inserts a new node at the front of the linked list. It takes two parameters: a pointer to the head of the linked list called start and a pointer to the new node called newptr. It sets the next member of the new node to point to the current head of the linked list and then returns a pointer to the new node.

struct digit * reverseNumber(struct digit * start) {
    //! heap=showMemory(start=336, cursors=[ptr,start,bstart,newdigit])
    struct digit *ptr = start;
    struct digit *bstart = NULL;
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
This function reverses the linked list. It takes a pointer to the head of the linked list called start as a parameter. It declares three pointers called ptr, bstart, and newdigit and initializes ptr with start. It also sets bstart to NULL. It then checks if the linked list is empty or not. If it is not empty, it creates a new node using the createDigit function and stores the value of the num member of the first node of the original linked list in it. It sets bstart to point to the new node and updates ptr point to the second node of the original linked list.

It then enters a while loop and iterates through the remaining nodes of the original linked list. For each node, it creates a new node using the createDigit function and stores the value of the num member of the current node in it. It then inserts the new node at the front of the reversed linked list using the insertAtFront function and updates the ptr pointer to point to the next node of the original linked list.

When it reaches the end of the original linked list, it returns a pointer to the head of the reversed linked list.
*/
