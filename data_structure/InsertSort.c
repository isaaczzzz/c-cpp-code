#include <stdio.h>
#define RecType int

RecType R[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

void insertSort(RecType R[], int n);

int main(void)
{
    insertSort(R, 9);
    for(int i = 0; i < 9; i++)
        printf("%d ", R[i]);
    system("pause");
    return 0;
}

//升序
void insertSort(RecType R[], int n)
{
    RecType tmp;
    for(int i = 1; i < n; i++) 
        if(R[i] < R[i - 1]) {
            tmp = R[i];
            int j = i - 1;
            do {
                R[j + 1] = R[j];
                j--;
            } while(j >= 0 && R[j] > tmp);
            R[j + 1] = tmp;
        }
}

