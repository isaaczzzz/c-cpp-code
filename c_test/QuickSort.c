/*quick sort*/
#include <stdio.h>
#include <stdlib.h>

void QuickSort(int *a, int l, int r);

int main(void)
{
    int n, i, j, max, min;
    int *a;

    scanf("%d", &n);

    malloc(n * sizeof(int));

    for(i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    QuickSort(a, 1, n);

    for(i = 1; i <= n; i++)
        printf("%d ", a[i]);
}

void QuickSort(int *a, int l, int r)
{
    if(l < r)
    {   
        int x = a[l]; // 基准值
        int i = l, j = r;

        while(i < j)
        {
            while(i < j && a[j] > x) //从右往左找比基准值小的
                j--;
            if(i < j)
                a[i++] = a[j];
            while(i < j && a[i] <= x) //从左往右找比基准值大的
                i++;
            if(i < j)
                a[j--] = a[i];
        }
        a[i] = x;
        QuickSort(a, l, i - 1);
        QuickSort(a, i + 1, r);
    }   
}
