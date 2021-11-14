#include <stdio.h>

int main(void) {
    int hour, min;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &min);
    
    printf("Equivalent 12-hour time: ");
    
    if(hour == 0) {
        printf("12:");
    } else if(hour < 12) {
        printf("%d:", hour);
    } else {
        printf("%d:", (hour == 12) ? hour:hour - 12);
    }
    
    if(min < 10) 
        printf("0%d", min);
    else 
        printf("%d", min);
    
    if (hour < 12)
        printf(" AM");
    else
        printf(" PM");
    return 0;
}