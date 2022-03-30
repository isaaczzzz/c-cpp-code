#include <stdio.h>
#include <string.h>

int str_replace(const char *in, char *out, int outlen, const char *oldstr, const char *newstr)
{
    int i = 0, num = 0, len = 0, newstrLen = 0;
    while(newstr[newstrLen++] != '\0');
    newstrLen--;
    
    while(in[i] != '\0') {
        if(in[i] == oldstr[0])
        {
            int tmp1 = i, tmp2 = i,  oldstrLen = 0, flag = 1;
            while(oldstr[oldstrLen] != '\0' && in[tmp1] != '\0')
            {
                if(oldstr[oldstrLen] != in[tmp1])
                {
                    flag = 0;
                    break;
                }
                tmp1++;
                oldstrLen++;
            }
            if(flag && len + oldstrLen - 1 <= outlen)
            {
                for(int j = 0; j < oldstrLen - 1; j++)
                {
                    out[tmp2] = newstr[j];
                    tmp2++;
                    len++;
                }
            }

        }
    }
}

int main()
{
    char in[20], out[20], oldstr[10], newstr[10];
    int outlen, result;
    scanf("%s %s %s", in, oldstr, newstr);
    result = str_replace(in, &out, outlen, oldstr, newstr);
    printf("%d %s", result, out);
    system("pause");
    return 0;
}