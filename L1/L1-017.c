//L1-017-到底有多二
#include <stdio.h>
#include <string.h>

int main(void)
{
    char num[51];
    int count = 0, countOf2 = 0;
    int i;
    float ans;

    scanf("%s", num);
    if (num[0] == '-')
    //负数的情况
    {
        count = strlen(num) - 1;
        for (i = 0; i < count + 1; i++)
        {
            if (num[i] == '2')
                countOf2++;
        }
        ans = ((double)countOf2 / (double)count) * 1.5;
        if ((num[count] - 48) % 2 == 0)
            ans *= 2;
    }
    else
    //正数的情况
    {
        count = strlen(num);
        for (i = 0; i < count; i++)
        {
            if (num[i] == '2')
                countOf2++;
        }
        ans = (double)countOf2 / (double)count;
        if ((num[count - 1] - 48) % 2 == 0)
            ans *= 2;
    }
    ans *= 100;
    printf("%.2f%%", ans);
    return 0;
}