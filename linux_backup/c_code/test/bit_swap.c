#include <stdio.h>

int main(void)
{
    unsigned int a, b;
    scanf("%u%u", &a, &b);
    a = a ^ b; //a, b不一样的位。
    b = a ^ b; //b ^ (a ^ b) = a
    a = a ^ b; //a ^ (a ^ b) = b
    printf("%u %u\n", a, b);
}