#include <stdio.h>
int main(void)
{
	int num, grade, i;
	int sum = 0;
	double doubSum;

	scanf("%d", &num);

	for (i=0 ; i < num ; i++)
	{
		scanf("%d", &grade);
		sum = sum + grade;
	}
	doubSum = (double) sum;
	printf("%.2lf", doubSum/num);

	return (0);
}
/*
You are helping a teacher average grades. You get bored computing averages by hand, so you decide to write a computer program to do the work for you.

Your program must first read an integer indicating the number of grades to be averaged. Next, your program will read the grades one by one, all of which are integers as well. Finally, your program will calculate and print the average of the grades to two decimal places.
*/
