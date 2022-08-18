//L1-041-я╟ур250
#include <stdio.h>

int is250(char *);

int main(void)
{
    char input[100000];
    int i = 0, space = 1;
    char * temp;
    while((input[i] = getchar()) != '\n')
        i++;

    temp = input;
    while (*(temp + 3) != '\0')
    {
        if (*temp == ' ')
            space++;
        if (is250(temp))
            break;
        temp++;
    }
    printf("%d", space);
    return 0;
}

int is250(char *start)
{
    char str[4] = "250";
    if (*start == str[0] && *(start + 1) == str[1] && *(start + 2) == str[2] && *(start - 1) != '-')
        return 1;
    return 0;
}