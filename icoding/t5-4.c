#include <stdio.h>

int main(void) {
    int lev;
    
    printf("Enter a wind speed: ");
    scanf("%d", &lev);

    if (lev < 1)
        printf("Calm");
    else if(lev >= 1 && lev <= 3)
        printf("Light air");
    else if(lev >=4 && lev <= 27)
        printf("Breeze");
    else if(lev >= 28 && lev <= 47)
        printf("Gale");
    else if(lev >= 48 && lev <= 63)
        printf("Storm");
    else 
        printf("Hurricane");
    return 0;
}