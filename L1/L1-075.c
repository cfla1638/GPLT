#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[10], year[10], month[10];
    scanf("%s", str);
    
    if (strlen(str) == 4)
    {
        if (str[0] == '2' && str[1] < '2')
        {
            year[0] = '2';
            year[1] = '0';
            year[2] = str[0];
            year[3] = str[1];
            year[4] = '\0';
            
            month[0] = str[2];
            month[1] = str[3];
            month[2] = '\0';
        }
        else if (str[0] < '2')
        {
            year[0] = '2';
            year[1] = '0';
            year[2] = str[0];
            year[3] = str[1];
            year[4] = '\0';
            
            month[0] = str[2];
            month[1] = str[3];
            month[2] = '\0';
        }
        else
        {
            year[0] = '1';
            year[1] = '9';
            year[2] = str[0];
            year[3] = str[1];
            year[4] = '\0';
            
            month[0] = str[2];
            month[1] = str[3];
            month[2] = '\0';
        }
    }
    else
    {
        year[0] = str[0];
        year[1] = str[1];
        year[2] = str[2];
        year[3] = str[3];
        year[4] = '\0';
        
        month[0] = str[4];
        month[1] = str[5];
        month[2] = '\0';
    }
    printf("%s-%s", year, month);
    return 0;
}