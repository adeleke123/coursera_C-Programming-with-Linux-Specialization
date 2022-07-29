#include <stdio.h>

int main(void)
{

    int i, num;

    scanf("%d", &num);

    for (i = 0; i <= 10; i++)
    {
        printf("%dx%d = %d\n", i, num, i*num);
    }

    return (0);
}

/*

In this activity, you want to improve your existing multiplication program (that prints the 8 times table). Your program should read an integer from the user (not you) and print the multiplication table for the number that they enter. To test if your program works, we will try running your code with several different inputs so make sure you don't hard code the solution.
*/
