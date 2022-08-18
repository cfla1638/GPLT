//L1-002-打印沙漏
#include <stdio.h>
#include <conio.h>

void Print(int *scaleBox, char printChar);
//int *MakeArray(int bar);
void PrintArray(int *array, int i);

int main(void)
{
    int input;
    char printChar;
    int i, scale, preScale, lastNum, scaleBox[50] = {0};

    //用户输入
    scanf("%d %c", &input, &printChar);

    scaleBox[0] = 1;
    for(i = 1, scale = 1; input >= scale; scale = scale + 2 * (2 * i + 1), i++)
    {
        //printf("%d ", scale);
        preScale = scale;
        scaleBox[i] = (2 * i + 1);
    }
    scaleBox[i-1] = 0;
    i -= 1;
    //printf("i = %d \n", i);
    //PrintArray(scaleBox, 50);

    lastNum = input - preScale;       //余数
    //scaleBox = MakeArray(i);
    Print(scaleBox, printChar);
    printf("%d", lastNum);

    getch();
    return 0;
}

void Print(int *scaleBox, char printChar)   //必须初始化scaleBox为0
{
    int i = 0, j = 0, h = 0;
    int mid, l;

    //扫描数组，得到可用位数
    while (scaleBox[i] != 0)
        i++;
    i -= 1;
    //printf("i = %d\n", i);
    //获取沙漏中间符号的位数
    mid = scaleBox[i] / 2;
    mid += 1;
    //printf("mid = %d\n", mid);
    //打印沙漏上端
    //处理每一行
    for (j = i; j >= 0; j--)
    {
        //打印空格占位
        for (l = 1; l < (mid - scaleBox[j] / 2); l++)
        {
            printf(" ");
        }
        //打印符号
        for (h = 0; h < scaleBox[j]; h++)
            printf("%c", printChar);
        printf("\n");
    }

    //重新初始化计数器
    l = 0;

    //打印沙漏下端
    //处理行
    for (j = 1; j <= i; j++)
    {

        //打印空格
        for (l = 1; l < (mid - scaleBox[j] / 2); l++)
        {
            printf(" ");
        }
        //打印符号
        for (h = 0; h < scaleBox[j]; h++)
            printf("%c", printChar);
        printf("\n");
    }
}

void PrintArray(int *array, int i)
{
    int j;
    for(j = 0;j < i; j++)
    {
        printf("%d ", array[j]);
    }
}