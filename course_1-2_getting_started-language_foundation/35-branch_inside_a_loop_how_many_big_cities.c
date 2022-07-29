#include <stdio.h>
int main(void)
{
    int nbCities;
    scanf("%d", &nbCities);
    int nbBigCities = 0;
    
    for (int i = 0; i < nbCities ; i++)
    {
        int population;
        scanf("%d", &population);
        
        if (population > 10 * 1000)
        {
            nbBigCities = nbBigCities + 1;
        }
    }
    printf("%d", nbBigCities);
    return 0;
}

/**
You want to determine the number of cities in a given region that have a population strictly greater than 10,000. To do this, you write a program that first reads the number of cities in a region as an integer, and then the populations for each city one by one (also integers).
Example
Input
6
1000
5000
15000
4780
0
23590
Output
2
*/

