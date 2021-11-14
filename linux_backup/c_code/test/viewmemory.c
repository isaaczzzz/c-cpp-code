#include <stdio.h>
#include <ctype.h>
#include <stdint.h>
//#include <unistd.h>

typedef unsigned char BYTE;;

int main(void)
{
    uint64_t addr;
    int i, n;
    BYTE *ptr;

    printf("Address of main function: %p\n", main);
    printf("Address of addr variable: %lx\n", (uint64_t)&addr);
    printf("\nEnter a (hex) address: ");
    scanf("%lx" ,&addr);
    printf("Enter number of bytes to view: ");
    scanf("%d", &n);

    putchar('\n');
    printf("  Address                  Bytes            Characters\n");
    printf("------------   -----------------------------------------\n");

    ptr = (BYTE *) addr;
    for(; n > 0; n -= 10)
    {
        printf("%8lX ", (uint64_t) ptr);
        for(i = 0; i < 10 && i < n; i++)
            printf("%.2lX ", (uint64_t)*(ptr + i));
        for(; i < 10; i++)
            printf("   ");
        printf("     ");
        for(i = 0; i < 10 && i < n; i++)
        {
            BYTE ch = *(ptr + i);
            if (!isprint(ch))
                ch = '.';
            printf("%c", ch);
        }
        putchar('\n');
        ptr += 10;
    }
    return 0;
}