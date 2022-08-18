#include <stdio.h>
#include <math.h>

int main(void)
{
    int N, maxCount, count, start;
    int i, j, temp;

    scanf("%d", &N);

    maxCount = count = start = 0;
    for (i = 2; i <= sqrt(N); i++)
    {
        count = 0;
        j = i;
        temp = N;
        while (temp % j == 0)
        {
            count++;
            temp /= j;
            j++;
        }
        if (count > maxCount)
        {
            maxCount = count;
            start = i;
        }
    }

    if (maxCount)
    {
        printf("%d\n", maxCount);
        for (i = 0; i < maxCount; i++)
        {
            printf("%d", start + i);
            if(i != maxCount - 1)
            {
                printf("*");
            }
        }
    }
    else
    {
        printf("%d\n%d",1,N);
    }

    return 0;
}