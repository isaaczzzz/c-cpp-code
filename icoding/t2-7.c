#include <stdio.h>

int main(void) {
    int dollar, twe, ten, fiv;
    printf("Enter a dollar amount: ");
    scanf("%d", &dollar);
    twe = dollar / 20;
    dollar %= 20;
    printf("$20 bills: %d\n", twe);
    ten = dollar / 10;
    dollar %= 10;
    printf("$10 bills: %d\n", ten);
    fiv = dollar / 5;
    dollar %= 5;
    printf("$5 bills: %d\n", fiv);
    printf("$1 bills: %d\n", dollar);
    return 0;
}