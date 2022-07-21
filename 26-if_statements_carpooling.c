#include <stdio.h>
int main(void)
{
	int passengers;
	float gas;
	float fees;
	scanf("%d %f", &passengers, &gas);

	if (passengers)
	{
		fees = ((1+gas) / (passengers+1));
	}
	else
	{
		fees = gas;
	}
	printf("%.2f", fees);

	return (0);
}

/*
You are planning a car trip so you post on a carpooling website in order to share the cost of the trip.

If you have 0 passengers the carpool site does not charge anything and you alone pay the full cost of the trip. If you have 1 or more passengers the carpool site adds a $1 fee to the cost of the trip and evenly divides the total cost ($1 fee + gas) among the passengers and you. You want to write a program that calculates the cost you have to pay. The program should read the number of passengers (an integer) and the cost of gas for the trip (a decimal number). The program should then print the cost that you have to pay (a decimal number) with 2 digits after the decimal point.
*/
