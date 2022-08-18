//L1-007-ÄîÊý×Ö
#include <stdio.h>
#include <string.h>

typedef struct 
{
    char pron[10];
}Pron;


int main(void)
{
    Pron p[10];
    int i, j, k, len;
    char input[50];

    strcpy(p[0].pron, "ling");
    strcpy(p[1].pron, "yi");
    strcpy(p[2].pron, "er");
    strcpy(p[3].pron, "san");
    strcpy(p[4].pron, "si");
    strcpy(p[5].pron, "wu");
    strcpy(p[6].pron, "liu");
    strcpy(p[7].pron, "qi");
    strcpy(p[8].pron, "ba");
    strcpy(p[9].pron, "jiu");

    scanf("%s", input);
    len = strlen(input);

    for (i = 0; i < len; i++)
    {
        if (input[i] == '-')
        {
            printf("fu ");
        }
        else if(i + 1 != len)
        {
            printf("%s ", p[input[i] - 48].pron);
        }
        else{
            printf("%s", p[input[i] - 48].pron);
        }
    }

    return 0;
}