#include<stdio.h>

int gcd(int m, int n){
    int k;
    k = n % m;
    if(k == 0){
        return m;
    }
    else gcd(k, m);
}

int main(void){
    int a, b, h;
    scanf("%d%d", &a, &b);
    if(a == 0 || b == 0){
        printf("math error!");
        return 0;
    }
    else{
        if(a > b){//a <= b
            int h;
            h = a;
            a = b;
            b = h;
        }
        printf("%d\n", gcd(a, b));
       /* printf("%o\n", gcd(a, b));
        printf("%x\n", gcd(a, b));
        printf("%#o\n", gcd(a, b));
        printf("%#x\n", gcd(a, b));*/
       // system("pause");
        getchar();
        getchar();
        return 0;
    }
}