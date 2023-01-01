#include <stdio.h>
#include <stdlib.h>
struct point{
    int x;
    int y;
};
void printPoint(struct point pt);
void readPoint(struct point * ptr);
void printPoly(struct point *ptr, int vertices);
int main(void) {
    //! showMemory(start=65520)
    struct point * polygon;
    int i, num;
    printf("How many vertices does your polygon have? ");
    scanf("%d", &num);
    polygon = (struct point *) malloc(num * sizeof(struct point));
    for (i=0; i<num; i++){
        readPoint(&polygon[i]);
    }
    printPoly(polygon, num);
    free(polygon);
	return 0;
}

void readPoint(struct point * ptr) {
    printf("\nEnter a new point: \n");
    printf("x-coordinate: ");
    scanf("%d", &ptr->x);
    printf("y-coordinate: ");
    scanf("%d", &ptr->y);
}

void printPoly(struct point *ptr, int vertices) {
    int i;
    for (i=0; i<vertices; i++) {
        printPoint(ptr[i]);
    }
}

void printPoint(struct point pt){
    printf("(%d, %d)\n", pt.x, pt.y);
}

Program Explanation

This C program is used to create and manipulate a polygon, which is a geometric shape with at least three sides and angles. The program first asks the user to input the number of vertices (corners) in the polygon. It then dynamically allocates memory for the polygon using the malloc function, which takes the number of vertices as an argument and returns a pointer to the memory location where the polygon can be stored.

The program then enters a loop where it reads in the x and y coordinates of each vertex of the polygon using the readPoint function. The readPoint function takes a pointer to a struct point as an argument and prompts the user to enter the x and y coordinates of a single point. The function stores the x and y coordinates in the x and y fields of the struct point object, respectively.

After all of the vertices have been read in, the program calls the printPoly function to print out the vertices of the polygon. The printPoly function takes a pointer to a struct point and the number of vertices as arguments, and it iterates through the array of struct point objects, calling the printPoint function on each one. The printPoint function takes a struct point as an argument and prints out the x and y coordinates of the point in the form "(x, y)".

Finally, the program frees the memory allocated for the polygon using the free function before exiting.




