#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "read_print.h"

#define NAME_LEN 25
#define MAX_LIST 100

struct student
{
    int id;
    char name[NAME_LEN + 1];
    int score;
} list[MAX_LIST];

int find_stu(int number, const struct student list[], int np);
void insert(struct student list[], int *np);
void search(const struct student list[], int np);
void roll_call(struct student list[], int np);
void print(const struct student list[], int np);

int main(void)
{
    int number_parts = 0;
    char code;

    srand((unsigned)time(NULL));

    print_head();

    while (1)
    {
        printf("Enter operation code:");
        scanf(" %c", &code);//必须先读入空格(跳过换行)
        while (getchar() != '\n');
        switch (code)
        {
        case 'i':
            insert(list, &number_parts);
            break;
        case 's':
            search(list, number_parts);
            break;
        case 'p':
            print(list, number_parts);
            break;
        case 'r':
            roll_call(list, number_parts);
            break;
        case 'q':
            return 0;
        default:
            putchar('\n');
            code_error();
        }
        printf("\n");
    }
}

int find_stu(int id, const struct student list[], int np)
{
    int i;

    for (i = 0; i < np; i++)
        if (list[i].id == id)
            return i;
    return -1;
}

void insert(struct student list[], int *np)
{
    int stu_id;

    if (*np == MAX_LIST)
    {
        database_full();
        return;
    }

    printf("Enter student's ID: ");
    scanf("%d", &stu_id);

    if (find_stu(stu_id, list, *np) >= 0)
    {
        exist();
        return;
    }

    list[*np].id = stu_id;
    printf("Enter student's name: ");
    read_line(list[*np].name, NAME_LEN);//跳过空格换行并读取name
    list[*np].score = 0;
    (*np)++;
}

void search(const struct student list[], int np)
{
    int i, id;

    printf("Enter student's id: ");
    scanf("%d", &id);
    i = find_stu(id, list, np);
    if (i >= 0)
    {
        putchar('\n');
        printf("Name : %s\n", list[i].name);
        printf("Score : %d\n", list[i].score);
    }
    else
        not_found();
}

void roll_call(struct student list[], int np)
{
    int num;
    if(np == 0)
    {
        database_empty();
        return;
    }
    num = rand() % np;
    lucky_student(list[num].id, list[num].name);
    list[num].score++;
}

void print(const struct student list[], int np)
{
    int i;
    putchar('\n');
    printf("ID   Name                               " 
           "Score\n");
    for (i = 0; i < np; i++)
        printf("%d    %-25s%11d\n", list[i].id, list[i].name, list[i].score);
}