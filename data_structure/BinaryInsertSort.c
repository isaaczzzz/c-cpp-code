#include <stdio.h>
#define RecType int

RecType R[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

void binInsertSort(RecType R[], int n);

int main(void)
{
    binInsertSort(R, 9);
    for(int i = 0; i < 9; i++)
        printf("%d ", R[i]);
    system("pause");
    return 0;
}

//升序
void binInsertSort(RecType R[], int n)
{
    RecType tmp;
    int low, high, mid;
    for(int i = 1; i < n; i++) {
        if(R[i] < R[i - 1]) {
            tmp = R[i];
            low = 0;
            high = i - 1;
            while(low <= high) {
                mid = (low + high) / 2;
                if(tmp < R[mid]) //插在左侧
                    high = mid - 1;
                else
                    low = mid + 1;//右侧
            }
        }
        for(int j = i - 1; j >= high + 1; j--)
            R[j + 1] = R[j];
        R[high + 1] = tmp;
    }
}

