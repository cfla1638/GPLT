//L1-003-个位数统计
#include <stdio.h>

int main()
{
    int i = 0, j = 0, h = 0;
    int count[10] = {0};
    char ch[1000] = {0};

    scanf("%s", ch);
    i = strlen(ch);

    for(j = 0;j < i; j++)
    {
        switch(ch[j])
        {
            case '0': count[0]++; break;
            case '1': count[1]++; break;
            case '2': count[2]++; break;
            case '3': count[3]++; break;
            case '4': count[4]++; break;
            case '5': count[5]++; break;
            case '6': count[6]++; break;
            case '7': count[7]++; break;
            case '8': count[8]++; break;
            case '9': count[9]++; break;
        }
    }
    for(; h < 10; h++)
    {
        if (count[h] != 0)
        printf("%d:%d\n", h, count[h]);
    }
    

    return 0;
}