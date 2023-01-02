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
int changeThrees(struct digit * start);


int main(void) {
    struct digit *start;
    start = readNumber();

    printf("The number ");
    printNumber(start);
    printf("was modified in %d places.\n", changeThrees(start));
    
    printf("The new number is ");
    printNumber(start);
    freeNumber(start);

    return 0;
}

struct digit * createDigit(int dig) {
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

int changeThrees(struct digit * start) {
    struct digit * ptr = start;
    int sum = 0;
    while (ptr!=NULL) {
        if (ptr->num == 3) {
            ptr->num = 9;
            sum++;
        }
        ptr = ptr->next;
    }
    return(sum);
}
/*
Program Explanation:

This program reads in a number entered by the user, replaces all occurrences of the digit 3 with the digit 9, and then prints the modified number.

#include <stdio.h>
#include <stdlib.h>
These two lines include the standard input/output and standard library headers.

struct digit {
    int num;
    struct digit *next;
};
This line defines a struct called "digit" that has two members: an int called "num" and a struct digit pointer called "next".

struct digit * createDigit(int);
struct digit * append(struct digit * end, struct digit * newDigptr);
void printNumber(struct digit *);
void freeNumber(struct digit *);
struct digit *readNumber(void); 
int divisibleByThree(struct digit * start);
int changeThrees(struct digit * start);
These lines declare six functions: createDigit(), append(), printNumber(), freeNumber(), readNumber(), and changeThrees(). The createDigit() and append() functions take in struct digit pointers as arguments and return struct digit pointers, while the other functions take in struct digit pointers or void and return void or int.

int main(void) {
    struct digit *start;
    start = readNumber();

    printf("The number ");
    printNumber(start);
    printf("was modified in %d places.\n", changeThrees(start));
    
    printf("The new number is ");
    printNumber(start);
    freeNumber(start);

    return 0;
}
This is the main function of the program. It declares a struct digit pointer called "start" and sets it equal to the return value of the readNumber() function, which reads in a number from the user and stores it as a linked list. It then prints the original number, calls the changeThrees() function to replace all occurrences of the digit 3 with the digit 9 and returns the number of replacements made, and prints the modified number. It finally calls the freeNumber() function to free the memory used by the linked list and returns 0.

struct digit * createDigit(int dig) {
    struct digit *ptr;
    ptr = (struct digit *) malloc(sizeof(struct digit));

This is the createDigit() function. It takes in an int called "dig" and returns a struct digit pointer. It declares a struct digit pointer called "ptr" and allocates memory for a new digit struct using malloc() from the stdlib library. It sets the "num" member of the struct to "dig" and the "next" member to NULL, and then returns a pointer to the struct.

struct digit * append(struct digit * end, struct digit * newDigptr) {
    end->next = newDigptr;
    return(end->next);
}
This is the append() function. It takes in two struct digit pointers: "end", which points to the last digit in the current linked list, and "newDigptr", which points to the new digit to be added to the list. It sets the "next" member of the "end" struct to "newDigptr" and then returns a pointer to the new end of the list (i.e. "newDigptr").

void printNumber(struct digit *start) {
    struct digit * ptr = start;
    while (ptr!=NULL) {
        printf("%d", ptr->num);
        ptr = ptr->next;
    }
    printf("\n");
}
This is the printNumber() function. It takes in a struct digit pointer called "start" and prints out the digits in the linked list starting from "start". It declares a struct digit pointer called "ptr" and sets it equal to "start". It then enters a while loop that continues until "ptr" is NULL. In each iteration of the loop, it prints out the "num" member of the current digit pointed to by "ptr" and sets "ptr" to the next digit in the list. When the end of the list is reached, it prints a newline character.

void freeNumber(struct digit *start) {
    struct digit * ptr = start;
    struct digit * tmp;
    while (ptr!=NULL) {
        tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}
This is the freeNumber() function. It takes in a struct digit pointer called "start" and frees the memory used by the linked list starting from "start". It declares two struct digit pointers: "ptr", which is set equal to "start", and "tmp", which is used to temporarily store the address of the next digit in the list. It enters a while loop that continues until "ptr" is NULL. In each iteration of the loop, it sets "tmp" to the address of the next digit in the list, frees the memory pointed to by "ptr", and sets "ptr" to the value of "tmp". When the end of the list is reached, all of the memory used by the linked list has been freed.

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

This is the readNumber() function. It reads in a number from the user and stores it as a linked list. It declares three struct digit pointers: "start", "end", and "newptr". It also declares a char called "c" and an int called "d". It sets "start" to NULL and then uses scanf() to read in a character from the user and store it in "c". It enters a while loop that continues until "c" is a newline character. In each iteration of the loop, it converts the character to an int by subtracting 48 and stores the result in "d". It then calls the createDigit() function to create a new digit struct with the value of "d" and stores a pointer to the struct in "newptr". If "start" is NULL (i.e. this is the first digit being added to the list), it sets "start" and "end" equal to "newptr". If "start" is not NULL, it calls the append() function to add "newptr" to the end of the list and sets "end" equal to the new end of the list. Finally, it uses scanf() to read in the next character from the user and stores it in "c". When the end of the input is reached, the function returns a pointer to the start of the linked list.

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
This is the divisibleByThree() function. It takes in a struct digit pointer called "start" and returns an int. It declares a struct digit pointer called "ptr" and sets it equal to "start". It also declares an int called "qsum" and sets it to 0. It enters a while loop that continues until "ptr" is NULL. In each iteration of the loop, it adds the "num" member of the current digit pointed to by "ptr" to "qsum" and sets "ptr" to the next digit in the list. When the end of the list is reached, it checks if "qsum" is divisible by 3

This is the changeThrees() function. It takes in a struct digit pointer called "start" and returns an int. It declares a struct digit pointer called "ptr" and sets it equal to "start". It also declares an int called "sum" and sets it to 0. It enters a while loop that continues until "ptr" is NULL. In each iteration of the loop, it checks if the "num" member of the current digit pointed to by "ptr" is equal to 3. If it is, it sets the "num" member to 9 and increments "sum". Finally, it sets "ptr" to the next digit in the list. When the end of the list is reached, it returns the value of "sum", which is the number of 3s that were changed to 9s in the list.
In this task you will work with the linked list of digits we have created in the lessons up to this point. As before you are provided with some code that you should not modify:

Question

A structure definition for the storage of each digit's information.
A main() function to test your code.
The functions createDigit(), append(), printNumber(), freeNumber(), readNumber() and divisibleByThree() (although you may not need to use all of these).
Your task is to write a new function changeThrees() which takes as input a pointer that holds the address of the start of a linked list of digits. Your function should change all of those digits in this linked list that equal 3 to the digit 9, and count how many replacements were made. The function should return this number of replacements.
*/
