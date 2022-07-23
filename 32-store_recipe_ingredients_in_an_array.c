#include<stdio.h>

int main()
{
	int arr[10];
	int index;
	int i;

	for (i=0 ; i<10 ; i++)
	{
		scanf("%d",&arr[i]);
	}

	scanf("%d",&index);
	if (index == 0)
	{
		printf("%d",arr[0]);
	}
	else if (index == 1)
	{
		printf("%d",arr[1]);
	}
	else if (index == 2)
	{
		printf("%d",arr[2]);
	}
	else if (index == 3)
	{
		printf("%d",arr[3]);
	}
	else if (index == 4)
	{
		printf("%d",arr[4]);
	}
	else if (index == 5)
	{
		printf("%d",arr[5]);
	}
	else if (index == 6)
	{
		printf("%d",arr[6]);
	}
	else if(index == 7)
	{
		printf("%d",arr[7]);
	}
	else if(index == 8)
	{
		printf("%d",arr[8]);
	}
	else if(index == 9)
	{
		printf("%d",arr[9]);
	}
	return (0);
}

/*
Your grandparents gave you a fantastic cooking recipe but you can never remember how much of each ingredient you have to use! There are 10 ingredients in the recipe and the quantities needed for each of them are given as input (in grams). Your program must read 10 integers (the quantities needed for each of the ingredients, in order) and store them in an array. It should then read an integer which represents an ingredient's ID number (between 0 and 9), and output the corresponding quantity.
*/
