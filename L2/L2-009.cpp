//L2-009 ÇÀºì°ü
#include <bits/stdc++.h>
using namespace std;

struct peo
{
    int num;
    int cnt = 0;
    double in = 0;

};

int main(void)
{
    peo P[10005];
    int N, K, num;
    double money;
    cin >> N;
    for (int i = 1; i <= N; i++)
        P[i].num = i;
    for (int i = 1; i <= N; i++)
    {
        cin >> K;
        for (int j = 0; j < K; j++)
        {
            cin >> num >> money;
            P[num].cnt++;
            P[num].in += money;
            P[i].in -= money;
        }
    }
    for (int i = 1; i <= N; i++)
        P[i].in /= 100;
    auto cmp = [&](peo a, peo b){
        if (a.in != b.in)   return a.in > b.in;
        else if (a.cnt != b.cnt) return a.cnt > b.cnt;
        else return a.num < b.num;
    };
    sort(begin(P) + 1, begin(P) + N + 1, cmp);
    for (int i = 1; i <= N; i++)
    {
        cout << P[i].num << " ";
        printf("%.2f\n", P[i].in);
    }

    return 0;
}