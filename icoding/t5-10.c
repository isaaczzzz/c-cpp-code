#include <stdio.h> 

int main(void) {
    int num, a;

    printf("Enter numerical grade: ");
    scanf("%d", &num);

    if(num > 100 || num < 0){
        printf("Error, grade must be between 0 and 100.");
        return 0;
    }

    a = num / 10;
    printf("Letter grade: ");

    if(num == 100) {
        putchar('A');
        return 0;
    }
    switch (a)
    {
    case 9:
        putchar('A');
        break;
    case 8:
        putchar('B');
        break;
    case 7:
        putchar('C');
        break;
    case 6:
        putchar('D');
        break;
    default:
        putchar('F');
        break;
    }

    return 0;
}