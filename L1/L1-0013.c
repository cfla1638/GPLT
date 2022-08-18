//L1-0013-¼ÆËã½×³ËºÍ
#include <stdio.h>

int factorial(int num);
int sum = 0;

int main(void)
{
    int input;
    scanf("%d", &input);
    factorial(input);
    printf("%d", sum);
    return 0;
}

int factorial(int num)
{
    int temp;
    if (num == 1)
    {
        sum += 1;
        return 1;
    }
    temp = num * factorial(num - 1);
    sum += temp;
    return temp;
}