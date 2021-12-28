/*
    What's the longest English word you can write on a seven-segment display?

    Author: Nicolò D'Addabbo
            nicolodaddabbo@gmail.com

    From an idea by Tom Scott
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_STR 200

int main()
{
    FILE *fp;
    fp = fopen("words.txt", "r");

    if (fp == NULL)
    {
        printf("Could not open the word file");
        return 1;
    }

    int c;
    int word_lenght = 0;
    int best_word_lenght = 0;
    bool ignore = false;
    char *word = (char *)malloc(MAX_STR * sizeof(char));
    char *best_word = (char *)malloc(MAX_STR * sizeof(char));

    while ((c = getc(fp)) != EOF)
    {
        if (c != '\n' && c != ' ' && c != '\0')
        {
            // printf("%c", c);
            word[word_lenght] = c;
            word_lenght++;
            c = tolower(c);
            if (c == 'k' || c == 'm' || c == 'v' || c == 'w' || c == 'x' || c == 'z')
                ignore = true;
        }
        else
        {
            // printf("\n");
            // printf(" %d\n", word_lenght);
            if (best_word_lenght < word_lenght && ignore == false)
            {
                // best_word = realloc(best_word, word_lenght);
                best_word_lenght = word_lenght;
                best_word = strcpy(best_word, word);
                printf("\nThe best word is: %s", best_word);
            }

            memset(word, 0, word_lenght);
            word_lenght = 0;
            ignore = false;
        }
    }

    printf("\nThe best word is: %s", best_word);

    fclose(fp);

    return 0;
}