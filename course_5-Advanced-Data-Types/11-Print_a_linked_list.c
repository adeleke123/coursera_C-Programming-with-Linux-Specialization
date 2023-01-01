#include <stdio.h>

struct point{
    int x;
    int y;
    struct point * next;
};
void printPoints(struct point *start);
int main(void) {
    //! showMemory(start=65520)
    struct point pt1 = {1, 2, NULL};
    struct point * start;
    struct point pt2 = {-2, 3, NULL};
    struct point pt3 = {5, -4, NULL};
    
    start = &pt1;
    pt1.next = &pt2;
    pt2.next = &pt3;
    
    printPoints(start);
    
	return 0;
}

void printPoints(struct point *start) {
    //! showMemory(start = 65520, cursors=[ptr])
    struct point * ptr;
    ptr = start;
    while (ptr!=NULL) {
        printf("(%d, %d)\n", ptr->x, ptr->y);
        ptr = ptr->next;
    }
}

/*
Progam Explanation

#include <stdio.h>

This line includes the standard I/O library in the program. This library includes functions for input and output, such as printf and scanf.

struct point{
int x;
int y;
struct point * next;
};
void printPoints(struct point *start);

This line declares a structure called "point" with three members: two integers, x and y, and a pointer to another point structure called "next." It also declares a function called "printPoints" that takes a pointer to a point structure as an argument.

int main(void) {

This line declares the main function of the program. The main function is the starting point of the program and is where the program begins executing.

struct point pt1 = {1, 2, NULL};
struct point * start;
struct point pt2 = {-2, 3, NULL};
struct point pt3 = {5, -4, NULL};

These lines declare three variables of type "point," pt1, pt2, and pt3, and initialize them with values. It also declares a pointer to a point structure called "start."

start = &pt1;
pt1.next = &pt2;
pt2.next = &pt3;

These lines set up a linked list using the "next" pointers. "start" is set to the address of pt1, which is the first element in the list. The "next" pointer of pt1 is set to the address of pt2, and the "next" pointer of pt2 is set to the address of pt3. This creates a linked list with three elements: pt1, pt2, and pt3.

printPoints(start);

This line calls the "printPoints" function and passes it the address of the first element in the linked list, "start."

return 0;
}

This line returns 0 to the operating system to indicate that the program has successfully completed.

void printPoints(struct point *start) {
//! showMemory(start = 65520, cursors=[ptr])
struct point * ptr;
ptr = start;
while (ptr!=NULL) {
printf("(%d, %d)\n", ptr->x, ptr->y);
ptr = ptr->next;
}
}

This is a function that takes a pointer to a point structure as an argument and prints the values of x and y for each element in the linked list. "ptr" is set to "start," which is the beginning of the list. The loop continues as long as "ptr" is not NULL, which is the end of the list. The values of x and y are printed using the arrow operator (->) to access the members of the structure pointed to by "ptr." "ptr" is then updated to point to the next element in the list using the "next" pointer.
*/
