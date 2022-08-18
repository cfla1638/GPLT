//L1-077 大笨钟的心情
#include <stdio.h>

int main(void)
{
    int Kimoji[24];
    int i, input;
    
    for (i = 0; i < 24; i++)
        scanf("%d", &Kimoji[i]);

    scanf("%d", &input);
    while (input >= 0 && input <=23)
    {
        printf("%d ", Kimoji[input]);
        if (Kimoji[input] > 50)
            printf("Yes\n");
        else
            printf("No\n");
        scanf("%d", &input);
    }
    return 0;
}