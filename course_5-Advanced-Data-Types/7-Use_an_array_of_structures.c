#include <stdio.h>
struct point{
    int x;
    int y;
};
void printPoint(struct point pt);
void readPoint(struct point * ptr);
void printTriangle(struct point *ptr);
int main(void) {
    //! showMemory(start=65520)
    struct point triangle[3];
    int i;
    for (i=0; i<3; i++){
        readPoint(&triangle[i]);
    }
    printTriangle(triangle);
	return 0;
}

void readPoint(struct point * ptr) {
    printf("\nEnter a new point: \n");
    printf("x-coordinate: ");
    scanf("%d", &ptr->x);
    printf("y-coordinate: ");
    scanf("%d", &ptr->y);
}

void printTriangle(struct point *ptr) {
    int i;
    for (i=0; i<3; i++) {
        printPoint(ptr[i]);
    }
}

void printPoint(struct point pt){
    printf("(%d, %d)\n", pt.x, pt.y);
}

/*
Program Explanation

This C program defines a struct called point that represents a point on a 2D plane with x and y integer fields. It has four functions:

printPoint: This function takes a point struct as input and prints it to the screen in the format "(x, y)". It uses the printf function to format the output.

readPoint: This function reads in a point from the user and stores it in a point struct. It takes a pointer to a point struct as input and uses the scanf function to read in the values for the x and y fields.

printTriangle: This function takes a pointer to an array of point structs as input and prints each point in the array to the screen using the printPoint function.

main: This is the main function of the program. It first declares an array of point structs called triangle with 3 elements. It then uses a for loop to read in 3 points from the user and store them in the triangle array using the readPoint function. It then calls the printTriangle function with the address of the triangle array as input to print the points to the screen. Finally, it returns 0 to indicate that the program has completed successfully.

*/
