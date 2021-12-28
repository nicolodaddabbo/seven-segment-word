/*
    What's the longest English word you can write on a seven-segment display?

    Author: Nicolò D'Addabbo
            nicolodaddabbo@gmail.com

    From an idea by Tom Scott
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 100

int main()
{
    FILE *fp;
    fp = fopen("test.txt", "r");

    if (fp == NULL)
    {
        printf("Could not open the word file");
        return 1;
    }

    int c;
    int word_lenght = 0;
    char *word = (char *)malloc(MAX_STR * sizeof(char));
    char *best_word = (char *)malloc(sizeof(char));

    while ((c = getc(fp)) != EOF)
    {
        if (c != '\n')
        {
            printf("%c", c);
            word[word_lenght] = c;
            word_lenght++;
        }
        else
        {
            printf(" %d\n", word_lenght);
            if (sizeof(best_word) < word_lenght){
                best_word = realloc(best_word, word_lenght);
                best_word = strcpy(best_word, word);
            }

            memset(word, 0, word_lenght);
            word_lenght = 0;
        }
    }

    printf("\nThe best word is: %s", best_word);

    fclose(fp);

    return 0;
}