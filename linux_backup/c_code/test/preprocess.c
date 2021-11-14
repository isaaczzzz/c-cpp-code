#include <stdio.h>
#define N  10
#define INC(x) ((x) + 1)
#define SUB(x, y) ((x) - (y)) //括号
#define SQR(x) ((x) * (x))
#define CUBE(x) (SQR(x) * x)
#define M1(x, y) x##y
#define M2(x, y) #x #y

int main(void)
{
    int a[N], i, j, k, m;

#ifdef N
    i = j;
#else
    j = i;
#endif

    i = 10 * INC(j);
    i = SUB(j, k);
    i = SQR(SQR(j));
    i = CUBE(j);

    int M1(j, k);
    i = M1(j, k);  //未定义

    puts(M2(i, j));//未声明头文件

/*定义已取消
#undef SQR
    i = SQR(j);
*/
/*重复定义 warning
#define SQR
    i = SQR(j);
*/
    return 0;
}