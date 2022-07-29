#include <stdio.h>

int main(void) 
{
    int num, i;
    char first[101], last[101];
    scanf("%d", &num);

    for (i = 0; i < num; i++)
    {
       scanf("%s", first);
       scanf("%s", last);
       printf("%s %s\n", last, first);
    }

    return (0);
}

/*
Your local public library keeps a record of all of its patrons, consisting of index cards that hold a person's last name followed by their first name (so that the cards can easily be sorted alphabetically by last name). Unfortunately a computer error led to incorrectly printed forms last month, resulting in a number of cards that list the patron's first name followed by their last name rather than the other way around. Your job is to read these pairs of first and last names and display them in the correct order (last name followed by first name). You may assume that each first and last name has at most 100 characters and does not contain any spaces.

Your program should first read the total number of names (an integer) in order to know how many index cards need to be processed altogether. Next,  for each index card, your program should read a patron's first name and last name and then display these names correctly, that is on one line, the last name followed by one space, followed by the first name.  Your program should print the reversed name immediately after reading the patron's names (ie, it should not wait until it has read all of the index cards to begin printing). 

Note that, for ease of viewing, the example below shows all of the inputs in one block and all of the outputs in another block, despite the fact that programmatically these will be interspersed.  

Example
Input:
4
Alan Turing
Ada Lovelace
Donald Knuth
Claude Shannon
 

Output:
Turing Alan
Lovelace Ada
Knuth Donald
Shannon Claude

*/
