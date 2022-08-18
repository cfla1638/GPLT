#include <stdio.h>

int main(void)
{
    int n, i, j;
    int sum1, sum2;
    char input[100][10];

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%s", &input[i]);

    for (i = 0; i < n; i++)
    {
        sum1 = input[i][0] + input[i][1] + input[i][2];
        sum2 = input[i][3] + input[i][4] + input[i][5];
        if (sum1 == sum2)
            printf("You are lucky!\n");
        else
            printf("Wish you good luck.\n");
    }

    return 0;
}