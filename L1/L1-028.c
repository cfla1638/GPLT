//L1-028-ÅĞ¶ÏËØÊı
#include <stdio.h>
#include <math.h>

int main(void)
{
    long long input[10];
    int count;
    long long i, j;
    int tag = 1;
    
    scanf("%d", &count);
    for (i = 0; i < count; i++)
        scanf("%lld", &input[i]);

    for (i = 0; i < count; i++)
    {
        for (j = 2 ; j <= (int)sqrt((double)input[i]); j++)
        {
            if ((input[i] % j) == 0)
            {
                printf("No\n");
                tag = 0;
                break;
            } 
        }
        if (tag)
            printf("Yes\n");
        tag = 1;
    }
    return 0;
}