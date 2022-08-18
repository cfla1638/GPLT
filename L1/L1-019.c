//L1-019-谁先倒
#include <stdio.h>

typedef struct
{
    int volume;
    int han;
    int hua;
    int in;
}People;


int main(void)
{
    People A, B;
    int n, i, sum;

    A.in = B.in = 0;

    scanf("%d %d", &A.volume, &B.volume);
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d %d %d %d", &A.han, &A.hua, &B.han, &B.hua);
        sum = A.han + B.han;
        /*test
        printf("A.han = %d A.hua = %d\n", A.han, A.hua);
        printf("B.han = %d B.hua = %d\n", B.han, B.hua);
        printf("sum = %d\n", sum);
        */
       //不知道为什么不适用goto就会出错
        if ((A.hua != sum && B.hua != sum))
            goto lab;
        else if(A.hua == sum && B.hua == sum)
            goto lab;
        else if (A.hua == sum)
        {
            A.in++;
            goto lab;
        } 
        else if(B.hua == sum);
        {
             B.in++;
            goto lab;
        }
        lab:
        /*test
        printf("A.volume = %d A.in = %d\n", A.volume, A.in);
        printf("A.volume - A.in = %d\n", A.volume - A.in);
        printf("B.volume = %d B.in = %d\n", B.volume, B.in);
        printf("B.volume - B.in = %d\n", B.volume - B.in);
        */
        if ((A.volume - A.in) < 0)
        {
            printf("A\n%d", B.in);
            return 0;
        }
        if ((B.volume - B.in) < 0)
        {
            printf("B\n%d", A.in);
            return 0;
        }
    }

    return 0;
}