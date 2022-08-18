#include <stdio.h>
#include <string.h>

int main(void)
{
    int n = 0;
    int i;
    char name[1000][20];

    scanf("%s", name[n]);
    while (strcmp(name[n], "."))
    {
        n++;
        scanf("%s", name[n]);
    }

    if (n < 2)
    {
        printf("Momo... No one is for you ...");
        return 0;
    }

    if ((n >= 2) && (n < 14))
    {
        printf("%s is the only one for you...", name[1]);
        return 0;
    }

    if (n >= 14)
    {
        printf("%s and %s are inviting you to dinner...", name[1], name[13]);
        return 0;
    }
    
    return 0;
}