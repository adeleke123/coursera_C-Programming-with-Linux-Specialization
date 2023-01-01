#include <stdio.h>

struct point{
    int x;
    int y;
    struct point * next;
};

int main(void) {
    //! showMemory(start=65520)
    struct point pt1 = {1, 2, NULL};
    struct point pt2 = {-2, 3, NULL};
    struct point pt3 = {5, -4, NULL};
    struct point * start, * ptr;
    
    start = &pt1;
    pt1.next = &pt2;
    pt2.next = &pt3;
    
    ptr = start;
    while (ptr!=NULL) {
        printf("(%d, %d)\n", ptr->x, ptr->y);
        ptr = ptr->next;
    }
	return 0;
}

/*
#include <stdio.h>

This line includes the standard I/O library in the program. This library includes functions for input and output, such as printf and scanf.

struct point{
int x;
int y;
struct point * next;
};

This line declares a structure called "point" with three members: two integers, x and y, and a pointer to another point structure called "next."

int main(void) {

This line declares the main function of the program. The main function is the starting point of the program and is where the program begins executing.

struct point pt1 = {1, 2, NULL};
struct point pt2 = {-2, 3, NULL};
struct point pt3 = {5, -4, NULL};
struct point * start, * ptr;

These lines declare three variables of type "point," pt1, pt2, and pt3, and initialize them with values. They also declare two pointers to point structures, "start" and "ptr."

start = &pt1;
pt1.next = &pt2;
pt2.next = &pt3;

These lines set up a linked list using the "next" pointers. "start" is set to the address of pt1, which is the first element in the list. The "next" pointer of pt1 is set to the address of pt2, and the "next" pointer of pt2 is set to the address of pt3. This creates a linked list with three elements: pt1, pt2, and pt3.

ptr = start;
while (ptr!=NULL) {
printf("(%d, %d)\n", ptr->x, ptr->y);
ptr = ptr->next;
}

This is a loop that iterates through the linked list and prints the values of x and y for each element. "ptr" is set to "start," which is the beginning of the list. The loop continues as long as "ptr" is not NULL, which is the end of the list. The values of x and y are printed using the arrow operator (->) to access the members of the structure pointed to by "ptr." "ptr" is then updated to point to the next element in the list using the "next" pointer.

return 0;
}

This line returns 0 to the operating system to indicate that the program has successfully completed.
*/
