#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char c;
    
    while((c = getchar()) != '\n')
    {
        if(c > 64 && c < 68)
            putchar('2');
        else if(c > 67 && c < 71)
            putchar('3');
        else if(c > 70 && c < 74)
            putchar('4');
        else if(c > 73 && c < 77)
            putchar('5');
        else if(c > 76 && c < 80)
            putchar('6');
        else if(c > 79 && c < 84)
            putchar('7');
        else if(c > 83 && c < 87)
            putchar('8');
        else if(c > 86 && c < 91)
            putchar('9');
        else  putchar(c);
    }
    return 0;
}
