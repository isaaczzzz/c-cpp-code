#include <stdio.h>
#include <string.h>
#define SIZE 25

int main(void)
{
    char sma[SIZE] = "";
    char lar[SIZE] = "";
    char word[SIZE];
    _Bool end = 0;

    scanf("%s", sma);
    strcpy(lar, sma);
    while (!end)
    {
        scanf("%s", word);
        if(strlen(word) == 4)
            end = 1;
        if (strcmp(sma, word) > 0)
            strcpy(sma, word);
        if (strcmp(lar, word) < 0)
            strcpy(lar, word);
    }
    printf("Smallest word: %s\n", sma);
    printf("Largest word: %s\n", lar);
    return 0;
}