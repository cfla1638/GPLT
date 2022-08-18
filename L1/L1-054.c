//L1-054 福到了
#include <stdio.h>
#include <string.h>

int main(void)
{
    char input[100][100], ans[100][100];
    char printChar;
    int tag = 1;
    int N, i, j, m, n;

    //接受输入
    scanf("%c %d", &printChar, &N);
    getchar();
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            scanf("%c", &input[i][j]);   
        }
        input[i][N] = '\0';
        getchar();
    }

    //颠倒矩阵
    for (i = 0, m = N - 1; i < N; i++, m--)
    {
        for (j = 0, n = N - 1; j < N; j++, n--)
            ans[m][n] = input[i][j];
        ans[i][N] = '\0';    
    }
        
    for (i = 0; i < N; i++)
    {
        if (strcmp(input[i], ans[i]))
            tag = 0;
    }

    if (tag)
        printf("bu yong dao le\n");

    //输出矩阵
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (ans[i][j] != ' ')
                printf("%c", printChar);
            else
                printf(" ");   
        }
        printf("\n");
    }

    return 0;
}