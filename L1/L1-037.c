//L1-037-A³ıÒÔB
#include <stdio.h>

int main(void)
{
    float ans;
    int a, b;
    scanf("%d %d", &a, &b);
    if (b == 0)
    {
        printf("%d/%d=Error", a, b);
        return 0;
    }

    ans = (float)a / (float)b;
    if (b < 0)
        printf("%d/(%d)=%.2f", a, b, ans);
    else
        printf("%d/%d=%.2f", a, b, ans);
    return 0;
}