#include <stdio.h>

int main(void)
{

    int i;

    for (i = 0; i < 3; i++)
    {
        printf("C is fun!\n");
    }

    printf("\n");

    for (i = 0; i < 5; i++)
    {
        printf("We can do everything with it!\n");
    }

    return (0);
}

/*
 
You would like to display the same thing multiple times, but you do not wish to have to re-type it multiple times in your program.

Please print the following text to the screen:

C is fun!
C is fun!
C is fun!

We can do everything with it!
We can do everything with it!
We can do everything with it!
We can do everything with it!
We can do everything with it!

Simple, right? So now let's make this more difficult! You are only allowed to use three "printf" statements, and on top of that, you are not allowed to repeat text inside any of your printf statements.

Warning: Your output needs to look exactly like the above output.
*/
