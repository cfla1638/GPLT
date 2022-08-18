//L1-047-װ˯
#include <stdio.h>

typedef struct
{
    char * name [10];
    int breath;
    int bump;
}People;


int main(void)
{
    People list[10];
    int i, n;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%s %d %d", &list[i].name, &list[i].breath, &list[i].bump);

    for (i = 0; i < n; i++)
    {
        if (list[i].breath > 20 || list[i].breath < 15 || list[i].bump > 70 || list[i].bump < 50)
            printf("%s\n", list[i].name);
    }
    return 0;
}