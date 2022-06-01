#include <stdio.h>
#define RecType int

RecType R[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

void shellSort(RecType R[], int n);

int main(void)
{
    shellSort(R, 9);
    for(int i = 0; i < 9; i++)
        printf("%d ", R[i]);
    system("pause");
    return 0;
}

//升序
void shellSort(RecType R[], int n)
{
    RecType tmp;
    int d = n / 2; //初始化增量
    
    while(d > 0) {
        for(int i = d; i < n; i++) {
            tmp = R[i];
            int j = i - d;
            while(j >= 0 && tmp < R[j]) {
                R[j + d] = R[j];
                j -= d;
            }
            R[j + d] = tmp;
        }
        d /= 2; // 增量减小
    }
}