//L1-040-最佳情侣身高差
#include <stdio.h>

int main(void)
{
    int n, i;
    char gender[10];
    float height1[10], height2;
    scanf("%d", &n);
    while (getchar() != '\n')
            continue;
    for (i = 0; i < n; i++)
    {
        scanf("%c %f", &gender[i], &height1[i]);
        while (getchar() != '\n')
            continue;
    }
    //for (i = 0; i < n; i++)
      //  printf("%c", gender[i]);
    for(i = 0; i < n; i++)
    {
        if (gender[i] == 'M')
        {
            height2 = height1[i] / 1.09;
            printf("%.2f\n", height2);
        }
        if (gender[i] == 'F')
        {
            height2 = height1[i] * 1.09;
            printf("%.2f\n", height2);
        }
    }
    return 0;
}