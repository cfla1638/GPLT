//L1-016-查验身份证
#include <stdio.h>
#include <ctype.h>
#define true 1
#define false 0


typedef struct 
{
    char cardNumber[20];
    int examine;
    int sum;
}IDCard;


int main(void)
{
    IDCard list[100];
    int i, n, j, tag;
    int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    int M[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%s", &list[i].cardNumber);
        list[i].examine = true;
        list[i].sum = 0;
    }

    //检查字符是否为数字
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 17; j++)
        {
            if (!isdigit(list[i].cardNumber[j]))
            {
                list[i].examine = false;
            }
        }
        //printf("list[%d].examine = %d\n", i, list[i].examine);
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 17; j++)
        {
            list[i].sum += ((int)list[i].cardNumber[j] - 48) * weight[j];
        }
        //printf("list[%d].sum = %d\n", i, list[i].sum);
        if (list[i].cardNumber[17] != M[(list[i].sum % 11)])
            list[i].examine = false;
        //printf("list[%d].examine = %d\n", i, list[i].examine);
    }

    tag = 1;
    for (i = 0; i < n; i++)
    {
        if (!list[i].examine)
        {
            printf("%s\n", list[i].cardNumber);
            tag = 0;
        }
    }
    if (tag)
        printf("All passed");
    return 0;
}