#include <iostream>

void write(int a[][10])
{
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
            std::cout << a[i][j] << ' ';
        std::cout << '\n';
    }
}
int main(int argc, char const *argv[])
{
    int a[10][10];
    int sum = 0;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            a[i][j] = ++sum;
    write(a);
    return 0;
}