#include <stdio.h>

int main(void)
{
    char c;
    int sum[11] = {0};
	int i;

    while((c = getchar()) != '\n')
        sum[c - 48]++;
    printf("Digit:	    0 1 2 3 4 5 6 7 8 9\n");
    printf("Occurrences:");
    for(i = 0; i < 10; i++)
        printf("%d ", sum[i]);
    return 0;
}
