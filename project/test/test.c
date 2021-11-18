#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
    time_t timep;
    struct tm *p;

    while(1){
        time(&timep);
        p = gmtime(&timep);
        printf("%d/%d/%d %d:%d:%d", p -> tm_year + 1900, p -> tm_mon + 1, p -> tm_mday, 
                                    p -> tm_hour + 8, p -> tm_min, p -> tm_sec);
        Sleep(1000);
        system("cls");
    }
    return 0;
}