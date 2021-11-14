#include <stdio.h>

int sum(int *start, const int *end);

int main(void) 
{
	int a[20], *pa;
	int i;

	pa = a; //pa = &a[0]
	for(i = 0; i < 5; i++)
		scanf("%d", pa + i); //scanf("%d", &a[i]);
	for(i = 0; i < 5; i++)
		printf("%d ", a[i]); //printf("%d ", *(pa + i));
    printf("\n%d", sum(a, a + i));    
	return 0;
}
/*
int sum(int *ar, int n) 
{
	int *pa;
	int i, total = 0;
	pa = ar;
	for(i = 0; i < n; i++)
		total += *(pa + i);
	return total;
}
*/
int sum(int *start, const int *end) //const:设置为只读，防止形参被错误更改
{
	int total = 0;
	while(start < end)
	{
		total += *start;
		start++;
	}
	return total;
}
