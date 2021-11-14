#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
char map[11][11];
char al;
int l, r; //行，列

void init();
void up();
void down();
void left();
void right();

int main(void)
{
	int dir;
	bool mr = true;
	srand((unsigned)time(NULL));
	init();

	while (al < 'Z' && mr)
	{
		dir = rand() % 4;
		switch (dir)
		{
		case 0: //up
			up();
			break;
		case 1: //down
			down();
			break;
		case 2: //left
			left();
			break;
		default: //right
			right();
			break;
		}
	}
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			if (!isalpha(map[i][j]))
				printf(".  ");
			else
				printf("%c  ", map[i][j]);
		}
		putchar('\n');
	}
//	system("pause");
	return 0;
}
void init()
{
	al = 'A';
	map[1][1] = al;
	l = r = 1;
}
void up()
{
	if ((l - 1) < 1 || isalpha(map[l - 1][r]))
        return;
	map[--l][r] = ++al;
}
void down()
{
	if ((l + 1) > 10 || isalpha(map[l + 1][r]))
        return;
	map[++l][r] = ++al;
}
void left()
{
	if ((r - 1) < 1 || isalpha(map[l][r - 1]))
        return;
	map[l][--r] = ++al;
}
void right()
{
	if ((r + 1) > 10 || isalpha(map[l][r + 1]))
        return;
	map[l][++r] = ++al;
}