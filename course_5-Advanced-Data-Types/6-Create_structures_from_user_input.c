#include <stdio.h>
struct point{
    int x;
    int y;
};
void printPoint(struct point pt);
void readPoint(struct point * ptr);
int main(void) {
    //! showMemory(start=65520)
    struct point z;
    readPoint(&z);
    printPoint(z);
	return 0;
}

void readPoint(struct point * ptr) {
    printf("\nEnter a new point: \n");
    printf("x-coordinate: ");
    scanf("%d", &ptr->x);
    printf("y-coordinate: ");
    scanf("%d", &ptr->y);
}

void printPoint(struct point pt){
    printf("(%d, %d)\n", pt.x, pt.y);
}

/*
Program Explanation

This C program defines a struct called point that represents a point on a 2D plane with x and y integer fields. It has three functions:

printPoint: This function takes a point struct as input and prints it to the screen in the format "(x, y)". It uses the printf function to format the output.

readPoint: This function reads in a point from the user and stores it in a point struct. It takes a pointer to a point struct as input and uses the scanf function to read in the values for the x and y fields.

main: This is the main function of the program. It first declares a point struct called z. It then calls the readPoint function with the address of z as input to read in a point from the user and store it in z. It then calls the printPoint function with z as input to print the point to the screen. Finally, it returns 0 to indicate that the program has completed successfully.

*/
