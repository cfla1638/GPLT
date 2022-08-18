//L1-025-正整数A+Bver3
//C 库函数 int atoi(const char *str) 把参数 str 所指向的字符串转换为一个整数（类型为 int 型）
//https://zhidao.baidu.com/question/307925165.html?qbl=relate_question_3&word=%25%2Ac%25%5B%5E%5Cn%5D%25%2Ac
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0

int main(void)
{
    char num1[50], num2[50];
    int n1, n2, sum;
    int inputTag1 = true, inputTag2 = true;
    int i, j;

    scanf("%s",num1);
    scanf("%s",num1);
    //有一行没有AC就是因为下面的格式化输入限定字符串。
	scanf("%*c%[^\n]%*c",num2);         //???
    n1 = strlen(num1);
    n2 = strlen(num2);

    for (i = 1; i < n1; i++)
    {
        if (num1[i] < '0' || num1[i] > '9')
            inputTag1 = false;
    }

    for (i = 1; i < n2; i++)
    {
        if (num2[i] < '0' || num2[i] > '9')
            inputTag2 = false;
    }

    if ((atoi(num1) > 1000) || (atoi(num1) < 1))
        inputTag1 = false;
    if ((atoi(num2) > 1000) || (atoi(num2) < 1))
        inputTag2 = false;

    if (!inputTag1 && !inputTag2)
    {
        printf("? + ? = ?");
        return 0;
    }
    if (!inputTag1 && inputTag2)
    {
        printf("? + %d = ?", atoi(num2));
        return 0;
    }
    if (!inputTag2 && inputTag1)
    {
        printf("%d + ? = ?", atoi(num1));
        return 0;
    }

    sum = atoi(num1) + atoi(num2);
    printf("%d + %d = %d", atoi(num1), atoi(num2), sum);
    return 0;
}