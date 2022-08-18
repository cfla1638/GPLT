//L1-027 Гізт
#include <stdio.h>

int main(void)
{
    int i, j, k, m;
    int pos[11];
    int visited[10] = {0};
    char input[12];
    int lineOne[11] = {-1};
    
    i = 0;
    while ((input[i] = getchar()) != '\n')
    {
        visited[input[i] - 48] = 1;
        i++;
    }

    for (i = 9, j = 0; i >= 0; i--)
    {
        if (visited[i])
        {
            lineOne[j] = i;
            j++;
        }
    }

    for (i = 0, k = 0; i < 11; i++, k++)
    {
        for (m = 0; m < j; m++)
        {
            if (lineOne[m] == input[i] - 48)
            {
                pos[i] = m;
            }
        }
    }
    printf("int[] arr = new int[]{");
    for (i = 0; i < j; i++)
    {
        printf("%d", lineOne[i]);
        if (i != j - 1)
            printf(",");
    }
    printf("};\n");
    printf("int[] index = new int[]{");
    for (i = 0; i < 11; i++)
    {
        printf("%d", pos[i]);
        if (i != 10)
            printf(",");
    }
    printf("};");
    return 0;
}