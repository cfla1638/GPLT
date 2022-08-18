//L2-005 集合相似度,set版本
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    set<int> set[55];
    int num[55];
    int N, K;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int t;
        cin >> num[i];
        for (int j = 0; j < num[i]; j++)
        {
            cin >> t;
            set[i].insert(t);
        }
    }

    cin >> K;
    int a, b;
    int Nc = 0, Nt = 0;
    for (int i = 0; i < K; i++)
    {
        Nc = 0; Nt = 0;
        cin >> a >> b;
        for (auto elem : set[a])
        {
            if (set[b].count(elem) != 0) //存在，共有的
                Nc++;
        }
        Nt = set[a].size() + set[b].size() - Nc;
        double ans;
        ans = (double)Nc / Nt;
        ans *= 100;
        printf("%.2f%\n", ans);
    }

    return 0;
}