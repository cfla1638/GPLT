//L1-078 吉老师的回归
//淦strstr不区分大小写
#include <stdio.h>
#include <string.h>

char *Strstr(const char *str1, const char *str2);

int main(void)
{
    char line[550];
    int i = 0, j = 0;
    int M, N;
    int count = 0;

    scanf("%d %d", &N, &M);
    getchar();
    for (; j < N; j++)
    {
        while ((line[i] = getchar()) !='\n')
            i++;
        line[i + 1] = '\0';
        i = 0;

        if (Strstr(line, "qiandao") != NULL || Strstr(line, "easy") != NULL)
            continue;

        if (count == N)
        {
            printf("Wo AK le\n");
            return 0;
        }

        if (count == M)
        {
            printf("%s", line);
            break;
        }
        count++;    
    }
    if (j == N)
    {
        printf("Wo AK le\n");
    }
    
    return 0;
}

char *Strstr(const char *str1, const char *str2)
{
    char *cp = (char*)str1;
    char *s1, *s2;
 
    if (!*str2)
        return((char *)str1);
 
    while (*cp)
    {
        s1 = cp;
        s2 = (char *)str2;
 
        while (*s1 && *s2 && !(*s1 - *s2))
            s1++, s2++;
 
        if (!*s2)
            return(cp);
 
        cp++;
    }
    return(NULL);
}