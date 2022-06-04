#include <stdio.h>
#define RecType int

RecType R[] = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1}; //从R[1]开始

void HeapSort(RecType R[], int n);
void sift(RecType R[], int low, int high);

int main(void)
{
    HeapSort(R, 9);
    for(int i = 1; i < 10; i++)
        printf("%d ", R[i]);
    system("pause");
    return 0;
}

//降序
void HeapSort(RecType R[], int n)
{
    RecType tmp;
    for(int i = n / 2; i >= 1; i--)
        sift(R, i, n);
    for(int i = n ; i > 1; i--) {
        tmp = R[1];
        R[1] = R[i];
        R[i] = tmp;
        sift(R, 1, i - 1);
    }
}

//大根堆
void sift(RecType R[], int low, int high) 
{
    int i = low, j = i * 2; //j为i左孩子
    RecType tmp = R[i];
    while(j <= high) {
        if(j < high && R[j] < R[j + 1])
            j++;
        if(tmp < R[j]) { //父结点小，继续向下调整
            R[i] = R[j];
            i = j;
            j = i * 2;
        } else 
            break;
    }
    R[i] = tmp;
}