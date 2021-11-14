#include <stdio.h> 

int main(void) {
    int num, i = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    while(1) {
        i += 2;
        if(i * i > num) break;
        printf("%d\n", i * i);
    }
    return 0;
}