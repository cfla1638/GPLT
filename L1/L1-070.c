#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[100][81] = {0};
    int m = 0, n = 0;
    int i, j;
    int count = 0, pos = -1;

    int t;
    //∂¡»° ‰»Î
    while (1)
    {
        str[m][n] = getchar();
        if ((str[m][n] == '.') && n == 0)
            break;
        if (str[m][n] == '\n')
        {
            str[m][n] = '\0';
            n = 0;
            m++;
            continue;
        }
        n++;
    }
    

    for (i = 0; i < m; i++)
    {
        if (strstr(str[i], "chi1 huo3 guo1"))
        {
            count++;
            if (pos == -1)
                pos = i + 1;
        }
    }
    if (pos == -1)
    {
        printf("%d\n", m);
        printf("-_-#");
        return 0;
    }
    printf("%d\n%d %d", m, pos, count);

    return 0;
}