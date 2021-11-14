#include <stdio.h>
#include <string.h>

int main(void)
{
    char a[50];
    char ch;
    int move, len, i = 0;

    while((ch = getchar()) != '\n')
        a[i++] = ch;
    scanf("%d", &move);
    
    len = strlen(a);
    for(i = 0; i < len; i++) 
    {
        if(a[i] >= 'A' && a[i] <= 'Z') // ||(a[i] >= 'a' && a[i] <= 'z')
        {
            if (a[i] + move > 'Z')
                a[i] = a[i] + move -26;
            else 
                a[i] += move;
        }
        else if(a[i] >= 'a' && a[i] <= 'z') // ||(a[i] >= 'a' && a[i] <= 'z')
        {
            if (a[i] + move > 'z')
                a[i] = a[i] + move -26;
            else 
                a[i] += move;
        }
    }
    for(i = 0; i < len; i++)
        printf("%c", a[i]);
    return 0;
}