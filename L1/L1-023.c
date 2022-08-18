//L1-023 Êä³öGPLT
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    int i, len;
    char input[10000];
    int GCount = 0, PCount = 0, LCount = 0, TCount = 0; 

    scanf("%s", input);
    for (i = 0; i < strlen(input); i++)
    {
        input[i] = toupper(input[i]);
    }

    for (i = 0; i < strlen(input); i++)
    {
        switch (input[i])
        {
            case 'G': GCount++; break;
            case 'P': PCount++; break;
            case 'L': LCount++; break;
            case 'T': TCount++; break;
        }
    }

    for (i = 0; i < strlen(input); i++)
    {
        if (GCount-- > 0)
            printf("G");
        if (PCount-- > 0)
            printf("P");
        if (LCount-- > 0)
            printf("L");
        if (TCount-- > 0)
            printf("T");
    }

    return 0;
}