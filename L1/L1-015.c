//L1-015-°Â°ÍÂí»­·½¿é
#include <stdio.h>

int main(void)
{
    char ch;
    float r, c;
    int i, j;
    scanf("%f %c", &c, &ch);
    
    r = c / 2;
    if ((r - (int)r) != 0)
        r++;
    
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            printf("%c", ch);
        printf("\n");
    }
    
    return 0;
}