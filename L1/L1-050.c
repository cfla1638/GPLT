#include <stdio.h>
#include <string.h>

char *Add(char *ch, int L);

int main(void)
{
    char list[100000][10];
    char end[10], ch[10];
    int L, N;
    int i, j;

    scanf("%d %d", &L, &N);

    for (i = 0; i < L; i++)
    {
        ch[i] = 'a';
        end[i] = 'z';
    }
    ch[i] = '\0';
    end[i] = '\0';

    i = 0;
    while (strcmp(list[i], end))
    {
        i++;
        strcpy(list[i], ch);
        strcpy(ch, Add(ch, L));
        
        printf("%s\n", list[i]);
    }
    printf("%s", list[i + 1 - N]);
    return 0;
}

char *Add(char *input, int L)
{
    int i, j;
    char ch[10];
    //便于调试
    strcpy(ch, input);
    ch[L - 1]++;

    //检查有无进位
    for (i = L - 1; i >= 0; i--)
    {
        if (ch[i] > 'z' && i)
        {
            ch[i] = 'a';
            ch[i - 1]++;
        }
    }
    strcpy(input, ch);
    return input;
}