#include<stdio.h>

unsigned char getChksum(unsigned char *p, int len);

int main(void)
{
	unsigned char id[13];
	scanf("%s", id);
	printf("做 %c 卷", getChksum(id, 13));
	system("pause");
	return 0;
}

unsigned char getChksum(unsigned char *p, int len)
{
	int num;
	num = (int)*(p + len - 1);
	return num % 2 ? 'A':'B';
}