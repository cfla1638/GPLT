//L1-069 Ì¥Ñ¹¼à²â
#include <stdio.h>

int main(void)
{
    int tyre[4], min, maxDif;
    int high, low, i;
    int highSeq = 0, lowSeq = 0;
    int problemCount = 0, problemAddress;

    scanf("%d %d %d %d %d %d", &tyre[0], &tyre[1], &tyre[2], &tyre[3], &min, &maxDif);

    high = low = tyre[0];
    for (i = 0; i < 4; i++)
    {
        if (tyre[i] > high)
        {
            high = tyre[i];
            highSeq = i;
        }
        if (tyre[i] < low)
        {
            low = tyre[i];
            lowSeq = i;
        }
    }

    for (i = 0; i < 4; i++)
    {
        if (tyre[i] < min)
        {
            problemCount++;
            problemAddress = i;
        }
    }
    if ((high - low) > maxDif)
    {
        problemCount++;
        problemAddress = lowSeq;
    }

    if (problemCount == 0)
    {
        printf("Normal");
        return 0;
    }
    if (problemCount == 1)
    {
        printf("Warning: please check #%d!", problemAddress + 1);
        return 0;
    }
    if (problemCount >= 2)
    {
        printf("Warning: please check all the tires!");
        return 0;
    }
    return 0;
}