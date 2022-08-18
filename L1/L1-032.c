//L1-032 Left-pad
#include <stdio.h>
#include <string.h>

int main(void)
{
    int len, fillLen;
    char ch, ans[10000], str[10000];
    int i, j;

    scanf("%d %c", &len, &ch);
    getchar();
    i = 0;
    while ((str[i] = getchar()) != '\n')
        i++;
    str[i] = '\0';

    for (i = i - 1,j = len - 1; ( i >= 0) && ( j >= 0); i--, j--)
    {
        ans[j] = str[i];
    }
    fillLen = len - strlen(str);
    if (fillLen >= 0)
    {
        for (i = 0; i < fillLen; i++)
            ans[i] = ch;
        printf("%s", ans);
    }
    else
    {
        printf("%s", ans);
    }

    return 0;
}