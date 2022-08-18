//L1-030-Ò»°ïÒ»
#include <stdio.h>

typedef struct
{
    char *name[50];
    int gender;
    int tag;
    int rank;
}Student;


int main(void)
{
    Student list[50];
    int i, j, n;
    scanf("%d", &n);
    int nowGender;

    for (i = 0; i < n; i++)
    {
        scanf("%d %s", &list[i].gender, list[i].name);
        list[i].rank = i;
        list[i].tag = 1;
    }

    nowGender = list[0].gender;
    for (i = 0; i < n / 2; i++)
    {
        if (list[i].tag)
        {
            printf("%s ", list[i].name);
            list[i].tag = 0;
            nowGender = list[i].gender;
    
            for (j = n - 1; j > list[i].rank; j--)
            {
                if (list[j].tag && (list[j].gender != nowGender))
                {
                    printf("%s\n", list[j].name);
                    list[j].tag = 0;
                    break;
                }
            }
        }
    }



    return 0;
}