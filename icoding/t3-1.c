#include <stdio.h> 

int main(void) {
    int m, d, y;
    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &m, &d, &y);
    printf("%d", y);
    if(m < 10)
        printf("0%d", m);
    else 
        printf("%d", m);
    if(d < 10)
        printf("0%d", d);
    else 
        printf("%d", d);
    return 0;
}