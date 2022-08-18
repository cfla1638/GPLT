//L1-039 π≈∑Á≈≈∞Ê
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[1001], print[100][100];
    int i, j, k, col, row;

    // ‰»Î
    scanf("%d", &row);
    getchar();
    i = 0;
    while ((str[i] = getchar()) != '\n')
        i++;
    str[i] = '\0';

    col = (strlen(str) - 1) / row + 1;

    for (i = 0; i < row; i++)
        print[i][col] = '\0';

    k = 0;
    for (i = col - 1; i >= 0; i--)
    {
        for (j = 0; j < row; j++)
        {
            if (k < strlen(str))
                print[j][i] = str[k++];
            else
                print[j][i] = ' ';
        }
    }

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%c", print[i][j]);
        }
        printf("\n");
    }
    return 0;
}