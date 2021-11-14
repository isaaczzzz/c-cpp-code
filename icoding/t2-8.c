#include <stdio.h> 

int main(void) {
    float rate, pay, loan, r, a1, a2, a3;
    printf("Enter amout of loan: ");
    scanf("%f", &loan);
    printf("Enter interest rate: ");
    scanf("%f", &r);
    printf("Enter monthly payment: ");
    scanf("%f", &pay);
    putchar('\n');

    rate = r / 100.0f / 12.0f;
    a1 = (loan - pay) + loan * rate;
    a2 = (a1 - pay) + a1 * rate;
    a3 = (a2 - pay) + a2 * rate;

    printf("Balance remaining after first payment: $%.2f\n", a1);
    printf("Balance remaining after second payment: $%.2f\n", a2);
    printf("Balance remaining after third payment: $%.2f\n", a3);
    
    return 0;
}