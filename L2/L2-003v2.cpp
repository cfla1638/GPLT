//sort
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
    
    int mooncake[1005];
    for (int i = 0; i < N; i++)
        mooncake[i] = i;
    auto cmp = [&](int a, int b){return rate[a] > rate[b];};
    sort(mooncake, mooncake + N, cmp);

    double ans = 0;
    for (int i = 0; i < N; i++)
    {
        if ((need - storage[mooncake[i]]) >= 0)
        {
            ans += price[mooncake[i]];
        }
        else
        {
            ans += price[mooncake[i]] * (need / storage[mooncake[i]]);
        }
        need -= storage[mooncake[i]];
        if (need <= 0)
            break;
    }
    
    printf("%.2lf", ans);
    return 0;
}