#include <stdio.h>

int main(void) {

    int i, length;
    int max = 0;
    int num = 0;
    char word[101];

    scanf("%d", &num);
    for(i = 0 ; i < num ; i++){
        scanf("%s", word);
        length = 0;
        while(word[length]!='\0'){
            length++;
        }
        if (length > max)
        	max = length;
    }

    printf("%d\n", max);
    return 0;
}

/*
Your job is to find the length of the longest word in a text with no punctuation or special characters of any kind - only contains words. To do so, please write a C-program that takes as a input first the number of words in a text, followed by all of the words in the text. The output of your program should be the length of the longest word in the text.

To simplify your program, you can assume that the longest word will not exceed 100 characters.

 

Examples
Input:
14
This is a simple example text
we have to find the largest word length
Output:
7
Input:
7
All cats are grey in the dark
Output:
4
*/
