#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

char contents[STACK_SIZE];
int top = 0;


void stack_overflow(void)
{
  printf("Stack overflow\n");
  exit(EXIT_FAILURE);
}

void stack_underflow(void)
{
  printf("Stack underflow\n");
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

void push(char ch)
{
  if (is_full())
    stack_overflow();
  else
    contents[top++] = ch;
}

char pop(void)
{
  if (is_empty())
    stack_underflow();
  else
    return contents[--top];

  return '\0'; /* prevents compiler warning due to stack_underflow() call */
}


int main(void)
{
    char ch;
    while((ch = getchar()) != '\n')
    {
        if(ch == '(' || ch == '[' || ch == '{')
            push(ch);
        else 
        {
            switch (pop())
            {
            case '{':
                if(ch != '}')
				{
                    printf("Parentheses/braces are NOT nested properly\n");
                		return 1;
				}
				break;
			case '[':
                if(ch != ']')
                {
					printf("Parentheses/braces are NOT nested properly\n");
                		return 1;
				}
				break;
			default:
                if(ch != ')')
                    {
						printf("Parentheses/braces are NOT nested properly\n");
                		return 1;
					}
				break;
            }
        }
    }
    printf("Parentheses/braces are nested properly\n");
	return 0;
}