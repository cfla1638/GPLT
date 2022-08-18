#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char *covTo26(int num, int n);

int main(void)
{
    int L, N;
    int num = 1;
    int i, j;

    scanf("%d %d", &L, &N);

    for (i = 0; i < L; i++)
        num *=26;

    num -= N;
    printf("%s", covTo26(num, L));
    return 0;
}

//这是一个进制转换函数，可以当作模板使用，num是一个十进制数，n控制转换后的位数，如果不够使用0填充
char *covTo26(int num, int n)
{
    int i, j, temp;
    static char ch[10] = {0};

    //计算二十六进制数的位数
    temp = num;
    temp = num;
    for (i = n - 1; i >= 0; i--)
    {
        for (j = n; j > 1; j--)
        {
            temp %= (int)pow(26, j - 1);
        }
        ch[i] = temp + 97;
        num /= 26;
        temp = num;
    }
    ch[n + 1] = '\0';
    return ch;
}