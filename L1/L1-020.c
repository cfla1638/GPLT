//L1-020 帅到没朋友
//垃圾算法，别看这个！！！！！！！！！！！！
#include <stdio.h>
#include <string.h>

int main(void)
{
    int n, i, j, k, m, allCount;
    int tag, totalTag, spaceTag;
    int count;
    char human[100000][6], str[10000][6];
    
    scanf("%d", &n);
    i = 0;
    while (n--)
    {
        scanf("%d", &count);
        for (j =0; j < count; j++, i++)
        {
            scanf("%s", &human[i]);
        }
    }
    allCount = i;

    scanf("%d", &n);
    for (j = 0, k = 0; j < n; j++, k++)
    {
        scanf("%s", &str[k]);
        for (m = 0; m < k; m++)
        {
            if (!strcmp(str[m], str[k]))
            {
                k--;
                break;
            }
        }
    }
    
    totalTag = 1;
    spaceTag = 1;
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < allCount; j++)
        {
            if (!strcmp(human[j], str[i]))
                tag = 0;
        }
        if (tag)
        {
            if(!spaceTag)
                printf(" ");
            spaceTag = 0;
            printf("%s", str[i]);
            totalTag = 0;
        }
        tag = 1;
    }
    if (totalTag)
        printf("No one is handsome");

    return 0;
}