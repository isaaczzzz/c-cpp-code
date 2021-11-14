#include <stdio.h>

int main(void) {
    float a;
    printf("Enter an amount: ");
    scanf("%f", &a);
    a *= 1.05f;
    printf("with tax added: $%.2f", a);
    return 0;
}