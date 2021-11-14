#include <stdio.h>

int main(void)
{
    int i, n;
    int *pa;
    scanf("%d", &n);

    int a[n];
    pa = a;

    for (i = 0; i < n; i++)
        scanf("%d", pa + i);
    
    for (i = n - 1; i >= 0; i--)
        printf("%d ", *(pa + i));
    putchar('\n');
    return 0;
}