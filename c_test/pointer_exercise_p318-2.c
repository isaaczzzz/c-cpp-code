#include <stdio.h>

void copy_arr(int target[], int source[], int n);
void copy_ptr(int *target, int *source, int n);
void copy_ptrs(int *target, int *start, const int *end) ;


int main(void)
{
    int source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    int target1[5];
    int target2[5];
    int target3[5];
    copy_arr(target1, source, 5);
    copy_ptr(target2, source, 5);
    copy_ptrs(target3, source, source + 5);
}
void copy_arr(int target[], int source[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        target[i] = source[i];
        printf("%d ", target[i]);
    }
    putchar('\n');
}
void copy_ptr(int *target, int *source, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        *(target + i) = *(source + i);
        printf("%d ", *(target + i));
    }
    putchar('\n');
}
void copy_ptrs(int *target, int *start, const int *end) 
{
    while(start < end) 
    {
        *target = *start;
        printf("%d ", *target);
        target++;
        start++;
    }
    putchar('\n');
}
