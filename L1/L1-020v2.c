//L1-020 ÀßµΩ√ª≈Û”—
#include <stdio.h>

int main(void)
{
    int visited[100000] = {0};
    int col, countOfCol, num, tag, count, spaceTag;
    int i, j, k;

    scanf("%d", &col);
    for (i = 0; i < col; i++)
    {
        scanf("%d", &countOfCol);
        if (countOfCol == 1)
        {
            scanf("%d", &num);
            continue;
        }
        for (j = 0; j < countOfCol; j++)
        {
            scanf("%d", &num);
            visited[num] = 1;
        }
    }

    tag = 1;
    spaceTag = 1;
    scanf("%d", &count);
    for (i = 0; i < count; i++)
    {
        scanf("%d", &num);
        if(!visited[num])
        {
            tag = 0;
            if (!spaceTag)
                printf(" ");
            spaceTag = 0;
            printf("%05d", num);
            visited[num] = 1;
        }
    }
    if (tag)
        printf("No one is handsome");

    return 0;
}