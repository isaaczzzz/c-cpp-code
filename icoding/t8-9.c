#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
char map[11][11];
char al;
bool mark[11][11] = {false};
int l, r; //行，列

void init();
bool up();
bool down();
bool left();
bool right();

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
			if (up())
				break;
			else if (down())
				break;
			else if (left())
				break;
			else if (right())
				break;
			else
				mr = false;
			break;
		case 1: //down
			if (down())
				break;
			else if (up())
				break;
			else if (left())
				break;
			else if (right())
				break;
			else
				mr = false;
			break;
		case 2: //left
			if (left())
				break;
			else if (down())
				break;
			else if (up())
				break;
			else if (right())
				break;
			else
				mr = false;
			break;
		default: //right
			if (right())
				break;
			else if (down())
				break;
			else if (left())
				break;
			else if (up())
				break;
			else
				mr = false;
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
	system("pause");
	return 0;
}
void init()
{
	al = 'A';
	map[1][1] = al;
	mark[1][1] = true;
	l = r = 1;
}
bool up()
{
	if ((l - 1) < 1 || mark[l - 1][r] == true)
		return false;
	map[--l][r] = ++al;
	mark[l][r] = true;
	return true;
}
bool down()
{
	if ((l + 1) > 10 || mark[l + 1][r] == true)
		return false;
	map[++l][r] = ++al;
	mark[l][r] = true;
	return true;
}
bool left()
{
	if ((r - 1) < 1 || mark[l][r - 1] == true)
		return false;
	map[l][--r] = ++al;
	mark[l][r] = true;
	return true;
}
bool right()
{
	if ((r + 1) > 10 || mark[l][r + 1] == true)
		return false;
	map[l][++r] = ++al;
	mark[l][r] = true;
	return true;
}