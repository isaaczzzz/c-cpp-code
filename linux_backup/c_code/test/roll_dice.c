#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>

int roll_dice(void);
bool play_game(void);

int main(void)
{
    srand((unsigned)time(NULL));
    char mark;
    int win = 0, loss = 0;

    do
    {
        if (play_game())
        {
            printf("You win!\n");
            win++;
        }
        else
        {
            printf("You lose!\n");
            loss++;
        }
        printf("\nPlay again? ");
        mark = getchar();
        getchar();
    } while (mark == 'y');
    
    printf("Wins: %d    Losses: %d", win, loss);
}

int roll_dice(void)
{
    int dice1, dice2;
    dice1 = rand() % 6 + 1;
    dice2 = rand() % 6 + 1;
    return dice1 + dice2;
}

bool play_game(void)
{
    int point, dice;

    point = roll_dice();
    printf("You rolled: %d\n", point);
    if (point == 7 || point == 11)
        return true;
    if (point == 2 || point == 3 || point == 12)
        return false;
    printf("Your point is %d\n", point);
    
    while (1)
    {
        dice = roll_dice();
        printf("You rolled: %d\n", dice);
        if (dice == 7)
            return false;
        if (dice == point)
            return true;
    }
}