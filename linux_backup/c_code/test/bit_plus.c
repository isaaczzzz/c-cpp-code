#include <stdio.h>

typedef unsigned int UINT;

UINT add(UINT a, UINT b);

int main(void)
{
    UINT a, b;
    scanf("%u%u", &a, &b);
    printf("%u\n", add(a, b));
}

UINT add(UINT a, UINT b)
{
    UINT sum, carry;
    sum = a ^ b; //合并0+1为1, 1+1, 0+0为0
    carry = a & b; //进位
    return carry ? add(sum, carry << 1) : sum;
    /*进位不为0时，需继续进位，直到进位为0*/
}

/******************************************************
 * 模拟二进制竖式计算。
 * 通过归纳发现，上下合并时，0+1为1, 1+1, 0+0为0，与^预算一致。
 * 仅1+1时需要进位，即&运算为真，进位时左移一位。
 * ***************************************************/
