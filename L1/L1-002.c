//L1-002-��ӡɳ©
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

    //�û�����
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

    lastNum = input - preScale;       //����
    //scaleBox = MakeArray(i);
    Print(scaleBox, printChar);
    printf("%d", lastNum);

    getch();
    return 0;
}

void Print(int *scaleBox, char printChar)   //�����ʼ��scaleBoxΪ0
{
    int i = 0, j = 0, h = 0;
    int mid, l;

    //ɨ�����飬�õ�����λ��
    while (scaleBox[i] != 0)
        i++;
    i -= 1;
    //printf("i = %d\n", i);
    //��ȡɳ©�м���ŵ�λ��
    mid = scaleBox[i] / 2;
    mid += 1;
    //printf("mid = %d\n", mid);
    //��ӡɳ©�϶�
    //����ÿһ��
    for (j = i; j >= 0; j--)
    {
        //��ӡ�ո�ռλ
        for (l = 1; l < (mid - scaleBox[j] / 2); l++)
        {
            printf(" ");
        }
        //��ӡ����
        for (h = 0; h < scaleBox[j]; h++)
            printf("%c", printChar);
        printf("\n");
    }

    //���³�ʼ��������
    l = 0;

    //��ӡɳ©�¶�
    //������
    for (j = 1; j <= i; j++)
    {

        //��ӡ�ո�
        for (l = 1; l < (mid - scaleBox[j] / 2); l++)
        {
            printf(" ");
        }
        //��ӡ����
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