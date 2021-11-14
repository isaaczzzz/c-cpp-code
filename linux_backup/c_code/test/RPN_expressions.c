#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_SIZE 100

int contents[STACK_SIZE];
int top = 0;


void stack_overflow(void)
{
  printf("Expression is too complex\n");
  exit(EXIT_FAILURE);
}

void stack_underflow(void)
{
  printf("Not enough operands in expression\n");
  exit(EXIT_FAILURE);
}


void make_empty(void)
{
  top = 0;
}

bool is_empty(void)
{
  return top == 0;
}

bool is_full(void)
{
  return top == STACK_SIZE;
}

void push(int ch)
{
  if (is_full())
    stack_overflow();
  else
    contents[top++] = ch;
}

int pop(void)
{
  if (is_empty())
    stack_underflow();
  else
    return contents[--top];

  return '\0'; /* prevents compiler warning due to stack_underflow() call */
}


int main(void)
{
    char exprs[STACK_SIZE];
	char ch;
	int a, b;
	
    make_empty();
  	while((ch = getchar()) != 'q')
	{
		getchar();
		if (isdigit(ch))
        	push(ch - '0');
	  	else
		{
			if (ch == '=')
			{
				printf("Value of expression: %d\n", pop());
				make_empty();
			}
			else {
				a = pop();
				b = pop();
				switch (ch)
				{
				case '+':
					b += a;
					break;
				case '-':
					b -= a;
					break;
				case '*':
					b *= a;
					break;
				default:
					b /= a;
					break;
				}
				push(b);
			}
		}
	}
	  return 0;
}