//L1-025-������A+B.c
//ԭʼ�İ��Ʒ����ʱ��֪������ʹ��atoi����ת���ַ��������Լ�ʵ�������ļӷ��������շ�����
#include <stdio.h>
#include <string.h>

char *Add(const char *num1, const char *num2, int n1, int n2);

int main(void)
{
    char num1[50], num2[50];
    int n1, n2;
    scanf("%s %s", num1, num2);
    //printf("%s\n%s", num1, num2);
    n1 = strlen(num1);
    n2 = strlen(num2);
    printf("%s", Add(num1, num2, n1, n2));
    return 0;
}

//Ĭ��n1>=n2
char *Add(const char *num1, const char *num2, int n1, int n2)
{
    static char sum[10] = {' '};
    int i;
    
    for (i = 0; i < n2; i++)
    {
      sum[3 - i] += (num1[n1 - 1 - i] + num2[n2 - 1 - i] - 48);
      //printf("%c\n", sum[3 - i]);
      if(sum[3 - i] > 57)
      {
          sum[3 - i] -= 10;
          sum[3 - 1 - i]++;
      }
    }
    
    //for (i = 0; i < 5; i++)
    //printf("%c ", sum[i]);
    sum[4] = '\0';
    //i = 0;
    //i = printf("%s", sum);
    //printf("i = %d", i);
    return sum;
}