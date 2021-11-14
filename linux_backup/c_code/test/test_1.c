#include <stdio.h>
#include <string.h>

void f(const char ch[])
{
    strcat(ch, "***");
}

int main(void)
{
    char ch[25];
    scanf("%s", ch);
    f(ch);
    printf("%s", ch);
    return 0;
}