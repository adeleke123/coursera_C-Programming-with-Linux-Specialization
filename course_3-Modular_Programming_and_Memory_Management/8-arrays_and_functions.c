#include <stdio.h>

void reverseArray(int *arr);

int main (void)
{
	int arr[6];
	int i;

	for (i = 0; i < 6; i++)
	{
		scanf("%d", &arr[i]);
	}

	reverseArray(arr);

	for (i = 0; i < 6; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}

void reverseArray(int *arr)
{
	int swap;

	swap = arr[5];
	arr[5] = arr[0];
	arr[0] = swap;
	
	swap = arr[4];
	arr[4] = arr[1];
	arr[1] = swap;
	
	swap = arr[3];
	arr[3] = arr[2];
	arr[2] = swap;
}

/*
Within this program, we will pass an array with 6 integers to a function, have the function swap the first and last integer, the second and the second to last integer, the third and the third to last integer.

The function is called reverseArray and doesn't return anything (void). It should take one parameter, representing the array of integers. 

The main function first reads 6 integers from the input, and assigns them to the array. The main function then calls reverseArray, passing the array as an argument.

The main function then prints the reversed array.

Examples
Input:
1 2 3 4 5 6
Output:
6 5 4 3 2 1
 

Input: 
9 12 3 25 11 5
Output:
5 11 25 3 12 9
*/
