//L1-011 A-B
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[10001] = {0};
    char ch;
    int n = 0;
    int i, temp;

    //接受所有输入
    while ((str[n] = getchar()) != '\n')
        n++;
    str[n] = '\0';

    temp = n;
    while ((ch = getchar()) != '\n')
    {
        for (i = 0; i < n; i++)
        {
            if (str[i] == ch)
            {
                str[i] = -1;
                temp--;
            }
        }
    }

    
    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] != -1)
        {
            printf("%c", str[i]);
        }
    }

    return 0;
}