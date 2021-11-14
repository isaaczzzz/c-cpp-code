#include <stdio.h>

void average(int (*p)[100], int m, const int n)
{
    int i, j, sum = 0;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == 0 || i == m - 1)
                sum += *(*(p + i) + j);
            else if (j == 0 || j == n - 1)
                sum += *(*(p + i) + j);
        }
    }
    printf("%.2f", (float)sum / 10);
}

int main()
{
    int m, n, i, j, a[100][100] = {0};
    printf("请输入一个m*n的矩阵\n");
    scanf("%d%d", &m, &n);
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    average(a, m, n);
    return 0;
}