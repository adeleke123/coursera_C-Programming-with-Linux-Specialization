#include <stdio.h>
#include <stdlib.h>
struct point{
    int x;
    int y;
    struct point * next;
};
void printPoints(struct point *start);
struct point * createPoint(int x, int y) ;
struct point * append (struct point * end, struct point * newpt);
void freePoints(struct point * start);
int main(void) {
    //! showMemory(start=65520)
    struct point * start, * end, * newpt;
    int num, i;
    int x, y;
    
    printf("How many points? ");
    scanf("%d", &num);
    for (i=0; i<num; i++) {
        printf("x = ");
        scanf("%d", &x);
        printf("y = ");
        scanf("%d", &y);
        newpt = createPoint(x,y);
        if (i==0) {
            start = end = newpt;
        } else {
            end = append(end,newpt);
        }
    }
    printf("You entered: ");
    printPoints(start);
    freePoints(start);
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

struct point * append (struct point * end, struct point * newpt) {
    end->next = newpt;
    return(end->next);
} 

struct point * createPoint(int x, int y) {
    struct point *ptr;
    ptr = (struct point *)malloc(sizeof(struct point));
    ptr->x = x;
    ptr->y = y;
    ptr->next = NULL;
    return(ptr);
}

void freePoints(struct point * start) {
    struct point * ptr = start;
    while (ptr!=NULL) {
        start = ptr;
        ptr = ptr->next;
        free(start);
    }
}

/*
Program Explanation

#include <stdio.h>
#include <stdlib.h>

This line includes the standard I/O library and the standard library in the program. The standard I/O library includes functions for input and output, such as printf and scanf. The standard library includes functions for performing general functions, such as memory allocation and conversion of numbers to strings.

struct point{
int x;
int y;
struct point * next;
};
void printPoints(struct point *start);
struct point * createPoint(int x, int y) ;
struct point * append (struct point * end, struct point * newpt);
void freePoints(struct point * start);

This line declares a structure called "point" with three members: two integers, x and y, and a pointer to another point structure called "next." It also declares four functions: "printPoints" that takes a pointer to a point structure as an argument, "createPoint" that takes two integers as arguments, "append" that takes two pointers to point structures as arguments, and "freePoints" that takes a pointer to a point structure as an argument.

int main(void) {

This line declares the main function of the program. The main function is the starting point of the program and is where the program begins executing.

struct point * start, * end, * newpt;
int num, i;
int x, y;

These lines declare three pointers to point structures, "start," "end," and "newpt," and two integers, "num" and "i."

printf("How many points? ");
scanf("%d", &num);

These lines prompt the user to enter the number of points and read the input from the user.

for (i=0; i<num; i++) {
printf("x = ");
scanf("%d", &x);
printf("y = ");
scanf("%d", &y);
newpt = createPoint(x,y);
if (i==0) {
start = end = newpt;
} else {
end = append(end,newpt);
}
}

This is a loop that reads the x and y values for each point from the user and creates a new point structure using the "createPoint" function. If it is the first point, "start" and "end" are both set to the address of the new point. If it is not the first point, the "append" function is called to add the new point to the end of the linked list and "end" is updated to the address of the new point.

printf("You entered: ");
printPoints(start);

These lines print the points that were entered by the user by calling the "printPoints" function and passing it the address of the first element in the linked list, "start."

freePoints(start);

This line calls the "freePoints" function and passes it the address of the first element in the linked list, "start." The "freePoints" function frees the memory allocated for each element in the linked list.

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

struct point * append (struct point * end, struct point * newpt) {
end->next = newpt;
return(end->next);
}

This is a function that takes two pointers to point structures as arguments: "end," which is the current end of the linked list, and "newpt," which is the new point to be added to the list. The "next" pointer of "end" is set to the address of "newpt," which makes "newpt" the new end of the list. The function then returns the address of "newpt."

struct point * createPoint(int x, int y) {
struct point *ptr;
ptr = (struct point *)malloc(sizeof(struct point));
ptr->x = x;
ptr->y = y;
ptr->next = NULL;
return(ptr);
}

This is a function that takes two integers as arguments: "x" and "y," which are the values for the x and y members of a point structure. The function uses the "malloc" function from the standard library to dynamically allocate memory for a point structure and stores the values of "x" and "y" in the structure. The "next" member of the structure is set to NULL. The function then returns the address of the new point structure.

void freePoints(struct point * start) {
    struct point * ptr = start;
    while (ptr!=NULL) {
        start = ptr;
        ptr = ptr->next;
        free(start);
    }
}
This is a function that takes a pointer to a point structure as an argument and frees the memory allocated for each element in the linked list. "ptr" is set to "start," which is the beginning of the list. The loop continues as long as "ptr" is not NULL, which is the end of the list. The memory allocated for the element pointed to by "start" is freed using the "free" function from the standard library. "start" is then updated to point to the next element in the list and the process is repeated until the end of the list is reached.
*/
