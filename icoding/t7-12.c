#include <stdio.h>

int main(void)
{
    float a, b;
    char ch;
    scanf("%f", &a);
    while((ch = getchar()) != '\n')
    {
        scanf("%f", &b);
        switch (ch)
        {
        case '+':
            a += b;
            break;
        case '-':
            a -= b;
            break;
        case '*':
            a *= b;
            break;
        default:
            a /= b;
            break;
        }
    }
    printf("Value of expression: %.1f\n", a);
    return 0;
}