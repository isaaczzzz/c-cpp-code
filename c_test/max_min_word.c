#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define SIZE 25

int main(void)
{
    char small[SIZE] = "";
    char large[SIZE] = "";
    char word[SIZE];
    bool end = false;

    scanf("%s", small);
    strcpy(large, small);
    while (!end)
    {
        scanf("%s", word);
        if(strlen(word) == 4)
            end = true;
        if (strcmp(small, word) > 0)
            strcpy(small, word);
        if (strcmp(large, word) < 0)
            strcpy(large, word);
    }
    printf("Smallest word: %s\n", small);
    printf("Largest word: %s\n", large);
    return 0;
}