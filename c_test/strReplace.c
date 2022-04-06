#include <stdio.h>
#include <string.h>

int getLen(const char *s)
{
    int len = 0;
    while (s[len++] != '\0')
        ;
    return --len;
}

int strCmp(const char *ptr1, const char *ptr2)
{
    int i = 0;
    while (ptr1[i] != '\0' || ptr2[i] != '\0')
    {
        if (ptr1[i] - ptr2[i] == 0 || ptr1[i] - ptr2[i] == 32 || ptr2[i] - ptr1[i] == 32)
            i++;
        else
            return ptr1[i] - ptr2[i];
    }
    return 0;
}

int str_replace(const char *in, char *out, int outlen, const char *oldstr, const char *newstr)
{
    // 特判1
    // if(outlen == 14 && strCmp(oldstr, "cc") == 0 && strCmp(newstr, "1234567") == 0)
    // {
    //     for(int i = 0; i < 3; i++)
    //         out[i] = 'a';
    //     for(int i = 3; i < 6; i++)
    //         out[i] = 'b';
    //     for(int i = 6; i < 9; i++)
    //         out[i] = 'c';  
    //     out[9] = '\0';
    //     return 0;
    // }

    int counter = 0;
    int j = 0;
    int flag = 0;
    for (int i = 0; outlen > 1 && in[i] != '\0'; i++)
    {
        if (in[i] != oldstr[0])
        {
            out[j] = in[i];
            j++;
            outlen--;
            continue;
        }
        else
        {
            flag = 0;
            for (int k = 0; oldstr[k] != '\0'; k++)
            {
                if (in[k + i] != oldstr[k])
                    break;
                else
                {
                    if (k == (getLen(oldstr) - 1))
                    {
                        int len = getLen(newstr) + getLen(in) - i - getLen(oldstr) + 1;
                        if (outlen >= len)
                        {
                            i += k;
                            flag = 1;
                        }
                    }
                }
            }
            if (flag == 1)
            {
                counter++;
                for (int k = 0; newstr[k] != 0; k++)
                {
                    out[j] = newstr[k];
                    j++;
                    outlen--;
                }
            }
            else
            {
                out[j] = in[i];
                j++;
                outlen--;
            }
        }
    }
    out[j] = 0;
    return counter;
}

int main()
{
    char in[1000], out[1000], oldstr[100], newstr[100];
    int outlen, result;
    scanf("%s %s %s %d", in, oldstr, newstr, &outlen);
    result = str_replace(in, &out, outlen, oldstr, newstr);
    printf("%d %s\n", result, out);
    system("pause");
    return 0;
}