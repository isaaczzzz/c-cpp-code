#include <iostream>
#define SIZE 105

void shuc(int a[][SIZE], const int m, const int n) {
    int k;
    std::cout << "Input the number:\n";
    std::cin >> k;
    std::cout << "The answer is:\n";
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            a[i][j] *= k;
            std::cout << a[i][j] << ' ';
        }
        std::cout << '\n';
        }
    return;
} 

void plus(char ch, int a[][SIZE], const int m, const int n) {
    int b[SIZE][SIZE];
    int t, k;
    std::cout << "Input line and row:\n";
    std::cin >> k >> t;
    if(m != k || n != t) {
        std::cout << "Math error!\n";
        return;
    }
    std::cout << "Input the data:\n";
    for(int i = 1; i <= k; i++)
        for(int j = 1; j <=t; j++){
            std::cin >> b[i][j];
            if (ch == '-')
                b[i][j] = -b[i][j];
        }
    std::cout << "The answer is:\n";
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j<= n; j++) {
            a[i][j] += b[i][j];
            std::cout << a[i][j] << ' ';
        }
        std::cout << '\n';
    }
    return;
}

int mult(int a[][SIZE], const int m, int n){
    int b[SIZE][SIZE], c[SIZE][SIZE] = {0};
    int t, k;
    std::cout << "Input line and row:\n";
    std::cin >> t >> k;
    if(n != t) {
        std::cout << "Math error!\n";
        return n;
    }
    std::cout << "Input the data:\n";
    for(int i = 1; i <= t; i++)
        for(int j = 1; j <= k; j++)
            std::cin >> b[i][j];
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= k; j++)
            for(int h = 1; h <= n; h++)
                c[i][j] += a[i][h] * b[h][j];
    std::cout << "The answer is:\n";
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= k; j++) {
            std::cout << c[i][j] << ' ';
            a[i][j] = c[i][j];
        }
        std::cout << '\n';
    }
    n = k;
    return n;
}

int main(int argc, char const *argv[]) {
    int a[SIZE][SIZE] = {0};
    int m, n;
    char ch;
    std::cout << "Input line and row:\n";
    std::cin >> m >> n;
    std::cout << "Input the data:\n";
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            std::cin >> a[i][j];
    while (1){
        std::cout << "ysf:\n";
        std::cin >> ch;
        if(ch == 'q')
            break;
        switch (ch) {
        case 'x':
            shuc(a, m, n);
            break;
        case '+':
            plus(ch, a, m, n);
            break;
        case '-':
            plus(ch, a, m, n);
            break;
        case '*':
            n = mult(a, m, n);
            break;
        default:
            std::cout << "Error!\n";
            break;
        }
    }
    return 0;
}