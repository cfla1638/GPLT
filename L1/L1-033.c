#include <stdio.h>
#include <math.h>

char *itoa(int num, int n);

int main(void)
{
    int year, count, age;
    char *yearChar;
    int n, i, j;

    scanf("%d %d", &year, &n);
    age = 0;

    //输入要求是在0~3000之间，所以去一个永远也不会达到的值做上限
    for (; year <=5000; year++)
    {
        count = 4;
        yearChar = itoa(year, 4);
        for(i = 0; i < 4; i++)
        {
            for (j = i + 1; j < 4; j++)
            {
                
                if (yearChar[i] == yearChar[j])
                {
                    
                    count--;
                    yearChar[j] = -1 - j;
                    //printf("%s\n", yearChar);
                }
            }
        }
        if (count == n)
        {
            printf("%d %04d", age, year);
            break;
        }
        age++;
    }

    
    return 0;
}


//PTA不支持这个函数，只能自己写了555
char *itoa(int num, int n)
{
    int i, j;
    int temp;
    static char numChar[10];
    
    

    temp = num;
    for (i = n - 1; i >= 4 - n; i--)
    {
        for (j = n; j > 1; j--)
        {
            temp %= (int)pow(10, j - 1);
        }
        numChar[i] = temp + 48;
        num -= temp;
        num /= 10;
        temp = num;
    }
    
    numChar[n + 1] = '\0';
    return numChar;
}