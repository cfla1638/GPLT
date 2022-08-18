//优先队列
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int N;
    double need;
    double storage[1005], price[1005];

    cin >> N >> need;
    for (int i = 0; i < N; i++)
        cin >> storage[i];
    for (int i = 0; i < N; i++)
        cin >> price[i];

    double rate[1005];

    for (int i = 0; i < N; i++)
        rate[i] = price[i] / storage[i];
    
    auto cmp = [&](int a, int b){return rate[a] < rate[b];};
    priority_queue<int, vector<int>, decltype(cmp)> heap(cmp);

    for (int i = 0; i < N; i++)
        heap.push(i);
    
    double ans = 0;
    while (!heap.empty())       //一开始的版本是for(;;),忽略了市场需求远大于自己的存货量的情况
    {
        int t;
        t = heap.top();
        heap.pop();
        if ((need - storage[t]) >= 0)
        {
            ans += price[t];
        }
        else
        {
            ans += price[t] * (need / storage[t]);
        }
        need -= storage[t];
        if (need <= 0)
            break;
    }
    printf("%.2lf", ans);
    return 0;
}