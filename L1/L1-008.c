//L1-008-求整数段和
#include <stdio.h>

int main(void)
{
    int A, B, i, sum;

    scanf("%d %d", &A, &B);

    sum = 0;
    for(i = 1; i < B - A + 2; i++)
    {
        printf("%5d", A + i - 1);
        sum += (A + i - 1);
        if((i % 5) == 0)
            printf("\n");
    }
    if(((i - 1) % 5) != 0)
        printf("\n");
    printf("Sum = %d", sum);
    return 0;
}