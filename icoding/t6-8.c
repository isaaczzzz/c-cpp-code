#include <stdio.h> 

int main(void) {
    int d, s, i = 0, j = 1;
    
    printf("Enter number of days in month: ");
    scanf("%d", &d);
    printf("Enter starting day of the week(1=Sun, 7=Sat): ");
    scanf("%d", &s);
    printf("日	一	二	三	四	五	六\n");
    while(--s > 0) {
        printf("   ");
        i++;
    }
    while(j <= d) {
        i++;
        printf("%-2d ", j);
        j++;
        if(i % 7 == 0)
            putchar('\n');
    }   
    return 0;
}