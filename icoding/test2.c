#include <stdio.h>
#include <string.h>
int main(void)
{
	char str[15] = "Computer";
	strcpy(&str[3], "com");
	puts(str);
}