#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 25

struct film
{
    char title[SIZE];
    int rating;
    struct film *next;
};

char *readLine(char *st, int n);
void outputList(struct film *list);

int main(void)
{
    struct film *head = NULL;
    struct film *prev, *cur;
    char input[SIZE];

    puts("First movie title:");
    while (readLine(input, SIZE) != NULL && input[0] != '\0')
    {
        cur = (struct film *)malloc(sizeof(struct film));
        if (head == NULL)
            head = cur;
        else
            prev->next = cur;
        cur->next = NULL;
        strcpy(cur->title, input);
        puts("rating <1-10>");
        scanf("%d", &cur->rating);
        while (getchar() != '\n')
            continue;
        puts("next movie title (empty line to stop):");
        prev = cur;
    }
    outputList(head);
    return 0;
}

void outputList(struct film *list)
{
    if (list == NULL)
        puts("No data");
    else
        puts("Here is the list:");
    for (; list != NULL; list = list->next)
        printf("Movie: %s  Rating %d\n", list->title, list->rating);
}

char *readLine(char *st, int n)
{
    char *retVal;
    char *find;

    retVal = fgets(st, n, stdin);
    if (retVal)
    {
        find = strchr(st, '\n'); //查找换行符
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return retVal;
}