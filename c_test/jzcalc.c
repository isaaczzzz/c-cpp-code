#include <stdio.h>
#define MAX 105

void plus(char ch) {
    int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];
    int m, t, n, k;
    printf("Input line and row:\n");
    scanf("%d%d", &m, &t);
    printf("Input the data:\n");
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= t; j++)
            scanf("%d", &a[i][j]);
    printf("Input line and row:\n");
    scanf("%d%d", &k, &n);
    if(m != k && t != k) {
        printf("Math error!");
        return;
    }
    printf("Input the data:\n");
    for(int i = 1; i <= t; i++)
        for(int j = 1; j <=n; j++){
            scanf("%d", &b[i][j]);
            if (ch == '-')
                b[i][j] = -b[i][j];
        }
    for(int i = 1; i <= m; i++)
        for(int j = 1; j<= t; j++)
            c[i][j] = a[i][j] + b[i][j];
     printf("The answer is:\n");
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= t; j++)
            printf("%d ", c[i][j]);
        printf("\n");   
    }
    return;
}

void mult(){
    int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];
    int m, t, n, k;
    printf("Input line and row:\n");
    scanf("%d%d", &m, &t);
    printf("Input the data:\n");
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <=t; j++)
            scanf("%d", &a[i][j]);
    printf("Input line and row:\n");
    scanf("%d%d", &k, &n);
    if(k != t) {
        printf("Math error!");
        return;
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
    return;
}

void shuc() {
    int a[MAX][MAX];
    int m, n, k;
    printf("Input the number:\n");
    scanf("%d", &k);
    printf("Input line and row:\n");
    scanf("%d%d", &m, &n);
    printf("Input the data:\n");
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <=n; j++) {
            scanf("%d", &a[i][j]);
            a[i][j] *= k;
        }
    printf("The answer is:\n");
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    return;
}

int main(void) {
    int p = 1;
    char ch;
    while(1) {
        if(p == 1) {
            printf("Please press Enter to continue...");
            p++;
        }
        if(p > 1)
            printf("\n");
        getchar();
        printf("ysf\n");
        scanf("%c", &ch);
        //printf("%c", c);
        if(ch == 'q')
            break;
        switch (ch)
        {
        case '+':{
            plus(ch);
            break;
        }
        case '-':{
            plus(ch);
            break;
        }
        case 'x':{
            shuc();
            break;
        }
        case '*':{
            mult();
            break;
        }
        default: {
            printf("!!\n");
            break;
        }
        }
    }
    getchar();
    getchar();
    return 0;
}