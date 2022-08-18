//L1-058 6∑≠¡À
#include <stdio.h>

int main(void)
{
    int i, j;
    int startTag = 0, sixCount = 0;
    char str[1000];

    while((str[i] = getchar()) != '\n')
        i++;
    for (j = 0; j <= i; j++)
    {
        if (!startTag && (str[j] == '6'))
        {
            startTag = 1;
            sixCount++;
            continue;
        }
        if (startTag && (str[j] == '6'))
        {
            sixCount++;
            continue;
        }
        if (startTag && str[j] != '6')
        {
            startTag = 0;
            if (sixCount <=3)
            {
                while (sixCount--)
                    printf("6");
            }
            if ((sixCount > 3) && (sixCount <= 9))
            {
                printf("9");
            }
            if (sixCount > 9)
                printf("27");
            sixCount = 0;
        }
        printf("%c", str[j]);
    }
    return 0;
}