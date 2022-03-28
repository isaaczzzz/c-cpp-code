#include <stdio.h>
#include <stdlib.h>

int str_compare(const char* ptr1, const char* ptr2){
    int i = 0;
    char a, b;
    while(ptr1[i] != '\0' && ptr2[i] != '\0') {
        if(ptr1[i] >= 'a' && ptr1[i] <= 'z')
            a =  ptr1[i] - 32;
        else 
            a = ptr1[i];
        if(ptr2[i] >= 'a' && ptr2[i] <= 'z')
            b =  ptr2[i] - 32;
        else 
            b = ptr2[i];
        if(a == b) {
            i++;
            continue;
        }
        else
            return a > b ? 1 : -1;
    }
    if(ptr1[i] != '\0')
        return 1;
    if(ptr2[i] != '\0')
        return -1;
    return 0;
}

int main(void) {
    char str1[105], str2[105];
    scanf("%s%s", &str1, &str2);
    printf("%d", str_compare(str1, str2));
    system("pause");
    return 0;
}