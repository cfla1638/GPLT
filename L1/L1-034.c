//L1-034 µ„‘ﬁ
#include <stdio.h>

typedef struct
{
    int seq;
    int frequency;
}Tag;


int main(void)
{
    Tag tag[1001], max;
    int n, count, seq;
    int i, j;

    //≥ı ºªØ
    for (i = 0; i < 1001; i++)
    {
        tag[i].seq = i;
        tag[i].frequency = 0;
    }
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &count);
        for (j = 0; j < count; j++)
        {
            scanf("%d", &seq);
            tag[seq].frequency++;
        }
    }
    
    max = tag[0];
    for (i = 0; i < 1001; i++)
    {
        if (tag[i].frequency >= max.frequency)
            max = tag[i];
    }
    printf("%d %d", max.seq, max.frequency);
    return 0;
}