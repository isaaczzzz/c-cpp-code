#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIGHTS 100

const int segments[10][7] = {
    {1, 1, 1, 1, 1, 1, 0}, /* 0 */
    {0, 1, 1, 0, 0, 0, 0}, /* 1 */
    {1, 1, 0, 1, 1, 0, 1}, /* 2 */
    {1, 1, 1, 1, 0, 0, 1}, /* 3 */
    {0, 1, 1, 0, 0, 1, 1}, /* 4 */
    {1, 0, 1, 1, 0, 1, 1}, /* 5 */
    {1, 0, 1, 1, 1, 1, 1}, /* 6 */
    {1, 1, 1, 0, 0, 0, 0}, /* 7 */
    {1, 1, 1, 1, 1, 1, 1}, /* 8 */
    {1, 1, 1, 1, 0, 1, 1}  /* 9 */
};
char dights[3][MAX_DIGHTS * 4];

void clear_dight_array(void);
void process_dights_array(int dight, int position);
void print_dights_array(void);

int main(void)
{
    int time_seg[15];
    unsigned char numbers[MAX_DIGHTS];
    int ch, i, j, num, year;
    time_t timep;
    struct tm *p;
    
    while(1) {
        time(&timep);
        p = gmtime(&timep);
        i = 0;
        clear_dight_array();
        
        year = p -> tm_year + 1900;
        for(j = 1000; j; j /= 10){
            printf("%d", year / j);
            process_dights_array(year / j, i++);
            year %= j;
        }               
        print_dights_array();
        Sleep(2000);
    }
    system("pause");
    return 0;
}

void clear_dight_array(void)
{
    memset(dights, ' ', sizeof dights);
}

void process_dights_array(int dight, int position)
{
    int n = position * 4;
    if (segments[dight][0])
        dights[0][n + 1] = '_';
    if (segments[dight][1])
        dights[1][n + 2] = '|';
    if (segments[dight][2])
        dights[2][n + 2] = '|';
    if (segments[dight][3])
        dights[2][n + 1] = '_';
    if (segments[dight][4])
        dights[2][n] = '|';
    if (segments[dight][5])
        dights[1][n] = '|';
    if (segments[dight][6])
        dights[1][n + 1] = '_';
}
void print_dights_array(void)
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < MAX_DIGHTS * 4; j++)
        {
            putchar(dights[i][j]);
        }
        putchar('\n');
    }
}