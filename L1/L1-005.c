//L1-005-¿¼ÊÔ×ùÎ»ºÅ
#include <stdio.h>
#define MAXIMUM 50
#define N 1000
#define M 1000

typedef struct 
{
    char examNum[MAXIMUM];
    int preNum;
    int realNum;
}Student;

int main(void)
{
    Student list[N];
    int n, i, m, searchList[M], j, h;

    //¶ÁÈ¡ĞÅÏ¢
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%s %d %d", &list[i].examNum, &list[i].preNum, &list[i].realNum);
    }
    scanf("%d", &m);
    for (j = 0; j < m; j++)
    {
        scanf("%d", &searchList[j]);
    }

    /*²âÊÔ
    for (h = 0; h < n; h++)
    {
        printf("%s %d %d\n", list[h].examNum, list[h].preNum, list[h].realNum);
    }
    ²âÊÔ*/
    for(h = 0; h < m; h++)
    {
        i = 0;
        while (searchList[h] != list[i].preNum)
        {
            i++;
        }
        printf("%s %d\n", list[i].examNum, list[i].realNum);
    }


    return 0;
}