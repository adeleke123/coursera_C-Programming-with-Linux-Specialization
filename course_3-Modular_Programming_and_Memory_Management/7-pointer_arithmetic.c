#include <stdio.h>
int main(void)
{


    int array[] = {4, 6, 12, -5, -7, 3, 1, 0, -10};
    int *ptr1, *ptr2;

    ptr1 = array+2;
    printf(" ptr1 %d\n", *ptr1 );
    printf(" *(ptr1 + 1) = %d\n", *(ptr1 + 1));
    ptr2 = &ptr1[5];
    printf(" ptr2 %d\n", *ptr2 );
    printf("*(ptr2 -3) = %d\n", *(ptr2 -3));

    return 0;

}

/*
quiz

Suppose you have made the following declarations:

int array[] = {4, 6, 12, -5, -7, 3, 1, 0, -10};
int *ptr1, *ptr2;
ptr1 = array+2;
ptr2 = &ptr1[5];
What is the value of *(ptr1+1)?

What is the value of *(ptr2-3)?
*/

