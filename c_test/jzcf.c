#include <stdio.h>
#define MAX 105

int main(void) {
    int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];
    int m, t, n, k;
    printf("Input line and row:\n");
    scanf("%d%d", &m, &t);
    printf("Input the data:\n");
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <=t; j++)
            scanf("%d", &a[i][j]);
    /*for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= t; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }*/
    printf("Input line and row:\n");
    scanf("%d%d", &k, &n);
    if(k != t) {
        printf("Math error!");
        return 0;
    }
    printf("Input the data:\n");
    for(int i = 1; i <= t; i++)
        for(int j = 1; j <=n; j++)
            scanf("%d", &b[i][j]);
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            for(int k = 1; k <= t; k++)
                c[i][j] += a[i][k] * b[k][j];
    printf("The answer is:\n");
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }
    getchar(); 
    getchar();        
    return 0;
}