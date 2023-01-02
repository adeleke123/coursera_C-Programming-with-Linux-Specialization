#include <stdio.h>
#include <stdlib.h>

struct digit {
    int num;
    struct digit *next;
};

struct digit * createDigit(int);
struct digit * append(struct digit * end, struct digit * newDigptr);
void printNumber(struct digit *start);

int main(void) {
    //! stackk = showMemory(start=65520)
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
    tmp = start->next;
    free(start);
    start = tmp;
    tmp = start->next;
    free(start);
    free(tmp);
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

void printNumber(struct digit *start){
    //! heap=showMemory(start=277, cursors=[ptr,start])
    struct digit * ptr = start;
    while (ptr!=NULL) {
        printf("%d", ptr->num);
        ptr = ptr->next;
    }
    printf("\n");
}
/*
Program Explanation

#include <stdio.h>

This line includes the header file "stdio.h", which stands for Standard Input Output. This file contains functions for performing input and output operations in C.

#include <stdlib.h>

This line includes the header file "stdlib.h", which stands for Standard Library. This file contains functions for performing general functions in C, such as memory allocation and converting numbers to strings.

struct digit {
int num;
struct digit *next;
};

This is a struct definition for a struct called "digit". A struct is a user-defined data type in C that can contain variables of different types. This struct has two fields: an integer called "num" and a struct pointer called "next" that points to another digit struct.

struct digit * createDigit(int);
struct digit * append(struct digit * end, struct digit * newDigptr);
void printNumber(struct digit *start);

These are function prototypes for three functions: "createDigit", "append", and "printNumber". The "createDigit" function takes in an integer as an argument and returns a struct pointer to a digit struct. The "append" function takes in two struct pointers as arguments and returns a struct pointer to a digit struct. The "printNumber" function takes in a struct pointer as an argument and does not return any value.

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
tmp = start->next;
free(start);
start = tmp;
tmp = start->next;
free(start);
free(tmp);
return 0;
}

This is the main function, which is the entry point of the program. It first declares four struct pointers: "start", "newDigptr", "end", and "tmp". It then declares three integers: "first", "second", and "third" and initializes them to 5, 3, and 7 respectively.

The function then calls the "createDigit" function, passing in "first" as an argument, and stores the returned struct pointer in "start". It then sets "end" to "start".

The function then calls the "createDigit" function, passing in "second" as an argument, and stores the returned struct pointer in "newDigptr". It then calls the "append" function, passing in "end" and "newDigptr" as arguments, and stores the returned struct pointer in "end".

The function then calls the "createDigit" function, passing in "third" as an argument, and stores the returned struct pointer in "newDigptr". It then calls the "append" function, passing in "end" and "newDigptr" as arguments, and stores the returned struct pointer in "end".

The function then calls the "printNumber" function, passing in "start" as an argument.

The function then uses the "tmp" pointer to store the next digit struct in the linked list, frees the memory pointed to by "start", and sets "start" to "tmp". It then repeats this process to free the memory pointed to by "start" and "tmp". Finally, the function returns 0 to indicate that the program has completed successfully.

struct digit *createDigit(int dig) {
struct digit *ptr;
ptr = (struct digit *) malloc(sizeof(struct digit));
ptr->num = dig;
ptr->next = NULL;
return ptr;
}

This is the "createDigit" function that was prototyped earlier. It takes in an integer called "dig" as an argument.

The function dynamically allocates memory for a digit struct using the malloc function and stores the returned memory address in "ptr". It then sets the "num" field of the digit struct to "dig" and the "next" field to NULL. It then returns "ptr".

struct digit * append(struct digit * end, struct digit * newDigptr) {
end->next = newDigptr;
return(end->next);
}

This is the "append" function that was prototyped earlier. It takes in two arguments: a struct pointer called "end" and a struct pointer called "newDigptr".

The function sets the "next" field of the digit struct pointed to by "end" to "newDigptr" and then returns "end->next".

void printNumber(struct digit *start){
struct digit * ptr = start;
while (ptr!=NULL) {
printf("%d", ptr->num);
ptr = ptr->next;
}
printf("\n");
}

This is the "printNumber" function that was prototyped earlier. It takes in a struct pointer called "start" as an argument.

The function declares a struct pointer called "ptr" and sets it to "start". It then enters a loop that continues as long as "ptr" is not NULL. Inside the loop, it prints the value of the "num" field of the digit struct pointed to by "ptr" and sets "ptr" to the next digit struct in the linked list using the "next" field. Once the loop has finished, the function prints a newline character.

*/
