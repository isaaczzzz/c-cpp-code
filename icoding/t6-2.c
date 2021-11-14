#include<stdio.h>

int gcd(int m, int n){
    int k;
    k = n % m;
    if(k == 0){
        return m;
    }
    else return gcd(k, m);
}

int main(void){
    int a, b, h;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    if(a > b){//a <= b
        h = a;
        a = b;
        b = h;
    }
        printf("Greatest common divisor: %d\n", gcd(a, b));
        return 0;
}