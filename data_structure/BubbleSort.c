#include <stdio.h>
#define RecType int

RecType R[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

void bubbleSort(RecType R[], int n);

int main(void)
{
    bubbleSort(R, 9);
    for(int i = 0; i < 9; i++)
        printf("%d ", R[i]);
    system("pause");
    return 0;
}

//升序
void bubbleSort(RecType R[], int n)
{
    RecType tmp;
    for(int i = 1; i < n; i++) 
        for(int j = 0; j < n - i; j++) {
            if(R[j] > R[j + 1]) {
                tmp = R[j];
                R[j] = R[j + 1];
                R[j + 1] = tmp;
            }
        }
}

//改进后的BubbleSort
/*
void bubbleSort(RecType R[], int n)
{
    RecType tmp;
    int exchange;
    for(int i = 1; i < n; i++) {
        exchange = 0;
        for(int j = 0; j < n - i; j++) {
            if(R[j] > R[j + 1]) {
                tmp = R[j];
                R[j] = R[j + 1];
                R[j + 1] = tmp;
                exchange = 1;
            }
            if(exchange == 0)
                return;
        }
    }
}
*/