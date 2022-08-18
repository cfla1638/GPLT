//L1-043 阅览室
#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    int SHour = -1;
    int SMin;
    int EHour = -1;
    int EMin;    
}Node;


int main(void)
{
    pair<int, double> ans[12];
    array<Node, 1005> data;
    int N, res;
    cin >> N;
    res = 0;
    int count = 0;
    double time = 0;
    while (res < N)
    {
        int num, hour, min;
        char c;
        cin >> num >> c;
        scanf("%d:%d", &hour, &min);  
        //结算
        if (num == 0)
        {
            if (count != 0)
                ans[res++] = pair<int, double>(count, (time / count));
            else
                ans[res++] = pair<int, double>(0,0);
            count = 0; time = 0;
            for (int i = 0; i < 1005; i++)
                data[i].SHour = data[i].EHour = -1;
            continue;
        }

        if (c == 'S')
        {
            //if (data[num].SHour == -1)
            if (1)  //多次借按最后一次算
            {
                data[num].SHour = hour;
                data[num].SMin = min;
            }
            else
                continue;
        }
        else if (c == 'E')
        {
            if (data[num].SHour != -1)
            {
                data[num].EHour = hour;
                data[num].EMin = min;
                //接下来结算清空
                count++;
                time += (60 * (data[num].EHour - (data[num].SHour + 1)) + data[num].EMin + (60 - data[num].SMin));
                //为下一次准备
                data[num].SHour = data[num].EHour = -1;
            }
            else
                continue;
        }

    }

    for (int i = 0; i < N; i++)
        printf("%d %.0f\n", ans[i].first, ans[i].second);

    return 0;
}