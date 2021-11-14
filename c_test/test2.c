#include <stdio.h>

void print(int (*p)[100], int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", *(*(p + i) + j));
        putchar('\n');
    }
}

int main(void)
{
    int m, n, i, j, a[100][100] = {0};
    printf("请输入一个m*n的矩阵\n");
    scanf("%d%d", &m, &n);
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    print(a, m , n);
}