#include <stdio.h>
#include <stdlib.h>

struct digit {
    int num;
    struct digit * next;
};
struct digit * createDigit(int dig);
struct digit * append(struct digit * end, struct digit * newDigitptr);
int main(void) {
    //! stack=showMemory(start=65520,cursors=[start,newDigitptr,end,tmp])
    struct digit *start, *newDigitptr, *end, *tmp;
    int first = 5;
    int second = 3;
    int third = 7;
    start = createDigit(first);
    end = start;
    newDigitptr = createDigit(second);
    end = append(end, newDigitptr);
    newDigitptr = createDigit(third);
    end = append(end, newDigitptr);
    // free needs to be added  here
    tmp = start->next;
    free(start);
    start = tmp;
    tmp = start->next;
    free(start);
    free(tmp);
    return 0;
}

struct digit * append(struct digit * end, struct digit * newDigitptr) {
    //! heap=showMemory(start=260, cursors=[end,newDigitptr])
    end->next = newDigitptr;
    end = newDigitptr;
    return(end);
}

struct digit * createDigit(int dig) {
    //! heap=showMemory(start=260, cursors=[ptr])
    struct digit *ptr;
    ptr = (struct digit *) malloc(sizeof(struct digit));
    ptr->num = dig;
    ptr->next = NULL;
    return ptr;
}

/*
Program Explanation

#include <stdio.h>

This line includes the header file "stdio.h", which stands for Standard Input Output. This file contains functions for performing input and output operations in C.

#include <stdlib.h>

This line includes the header file "stdlib.h", which stands for Standard Library. This file contains functions for performing general functions in C, such as memory allocation and converting numbers to strings.

struct digit {
int num;
struct digit * next;
};

This is a struct definition for a struct called "digit". A struct is a user-defined data type in C that can contain variables of different types. This struct has two fields: an integer called "num" and a struct pointer called "next" that points to another digit struct.

struct digit * createDigit(int dig);

This is a function prototype for a function called "createDigit", which takes in an integer called "dig" as an argument. The function returns a struct pointer to a digit struct.

struct digit * append(struct digit * end, struct digit * newDigitptr);

This is a function prototype for a function called "append", which takes in two arguments: a struct pointer called "end" and a struct pointer called "newDigitptr". The function returns a struct pointer to a digit struct.

int main(void) {
struct digit *start, *newDigitptr, *end, *tmp;
int first = 5;
int second = 3;
int third = 7;
start = createDigit(first);
end = start;
newDigitptr = createDigit(second);
end = append(end, newDigitptr);
newDigitptr = createDigit(third);
end = append(end, newDigitptr);
// free needs to be added here
tmp = start->next;
free(start);
start = tmp;
tmp = start->next;
free(start);
free(tmp);
return 0;
}

This is the main function, which is the entry point of the program. It first declares four struct pointers: "start", "newDigitptr", "end", and "tmp". It then declares three integers: "first", "second", and "third" and initializes them to 5, 3, and 7 respectively.

The function then calls the "createDigit" function, passing in "first" as an argument, and stores the returned struct pointer in "start". It then sets "end" to "start".

The function then calls the "createDigit" function, passing in "second" as an argument, and stores the returned struct pointer in "newDigitptr". It then calls the "append" function, passing in "end" and "newDigitptr" as arguments, and stores the returned struct pointer in "end".

The function then calls the "createDigit" function, passing in "third" as an argument, and stores the returned struct pointer in "newDigitptr". It then calls the "append" function, passing in "end" and "newDigitptr" as arguments, and stores the returned struct pointer in "end".

The function then uses the "tmp" pointer to store the next digit struct in the linked list, frees the memory pointed to by "start", and sets "start" to "tmp". It then repeats this process to free the memory pointed to by "start" and "tmp". Finally, the function returns 0 to indicate that the program has completed successfully.

struct digit * append(struct digit * end, struct digit * newDigitptr) {
end->next = newDigitptr;
end = newDigitptr;
return(end);
}

This is the "append" function that was prototyped earlier. It takes in two arguments: a struct pointer called "end" and a struct pointer called "newDigitptr".

The function sets the "next" field of the digit struct pointed to by "end" to "newDigitptr" and then sets "end" to "newDigitptr". It then returns "end".

struct digit * createDigit(int dig) {
struct digit *ptr;
ptr = (struct digit *) malloc(sizeof(struct digit));
ptr->num = dig;
ptr->next = NULL;
return ptr;
}

This is the "createDigit" function that was prototyped earlier. It takes in an integer called "dig" as an argument.

The function dynamically allocates memory for a digit struct using the malloc function and stores the returned memory address in "ptr". It then sets the "num" field of the digit struct pointed to by "ptr" to "dig" and the "next" field to NULL. It then returns "ptr".
*/
