#include <stdio.h>
#include <string.h>
#define SIZE 100

int main(void)
{
	int i = 0;
	char ch[SIZE];
	char c;
	while ((c = getchar()) != '\n')
		ch[i++] = c;
	for(i = strlen(ch) - 1; i >= 0; i--)
		putchar(ch[i]);
	return 0;
}