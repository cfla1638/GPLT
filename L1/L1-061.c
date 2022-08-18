//L1-061-新胖子公式.c
#include <stdio.h>

int main(void)
{
    float height, weight, ans;
    scanf("%f %f", &weight, &height);
    ans = weight / (height * height);
    printf("%.1f\n", ans);
    if(ans > (float)25)
        printf("PANG");
    else
        printf("Hai Xing");
    return 0;
}