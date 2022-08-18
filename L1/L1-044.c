#include <stdio.h>
#include <string.h>

int main(void)
{
    int K, n, i, count;
    char input[20];
    n = 0;

    scanf("%d", &K);
    scanf("%s", input);
    count = 0;
    while (strcmp(input, "End"))
    {
        if (count != 2)
        {
            count++;
            if (!strcmp(input, "ChuiZi"))
                printf("Bu\n");
            if (!strcmp(input, "Bu"))
                printf("JianDao\n");
            if (!strcmp(input, "JianDao"))
                printf("ChuiZi\n");
        } 
        else
        {
            count = 0;
            if (!strcmp(input, "ChuiZi"))
                printf("ChuiZi\n");
            if (!strcmp(input, "Bu"))
                printf("Bu\n");
            if (!strcmp(input, "JianDao"))
                printf("JianDao\n");
        }
        scanf("%s", input);
    }

    return 0;
}