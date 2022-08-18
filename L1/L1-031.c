//L1-031-到底是不是太胖了
#include <stdio.h>
#include <math.h>

typedef struct
{
    float height;
    float realWeight;
    float standardWeight;
}People;

int main(void)
{
    int count;
    int i;
    People list[20];
    
    scanf("%d", &count);
    for (i = 0; i < count; i++)
    {
        scanf("%f %f", &list[i].height, &list[i].realWeight);
        list[i].realWeight /= 2;
    }
    
    for (i = 0; i < count; i++)
    {
        list[i].standardWeight = (list[i].height - 100) * 0.9;
        if (fabs(list[i].realWeight - list[i].standardWeight) >= list[i].standardWeight * 0.1)
        {
            if (list[i].realWeight > list[i].standardWeight)
                printf("You are tai pang le!\n");
            if (list[i].realWeight < list[i].standardWeight)
                printf("You are tai shou le!\n");
        }
        else
        printf("You are wan mei!\n");
        
    }
    
    return 0;
}

/* 错误演示
#include <stdio.h>
#include <math.h>

typedef struct
{
    float height;
    float realWeight;
    float standardWeight;
}People;

int main(void)
{
    int count;
    int i;
    People list[20];
    
    scanf("%d", &count);
    for (i = 0; i < count; i++)
    {
        scanf("%f %f", &list[i].height, &list[i].realWeight);
        list[i].realWeight /= 2;
    }
    
    for (i = 0; i < count; i++)
    {
        list[i].standardWeight = (list[i].height - 100) * 0.9;
        if (fabs(list[i].realWeight - list[i].standardWeight) < list[i].standardWeight * 0.1)
            printf("You are wan mei!\n");
        else if (list[i].realWeight >= list[i].standardWeight * 1.1)
            printf("You are tai pang le!\n");
        else if (list[i].realWeight <= list[i].standardWeight * 0.9)
            printf("You are tai shou le!\n");
    }
    
    return 0;
}
*/