//L2-015 »¥ÆÀ³É¼¨
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int N, k, M;
    cin >> N >> k >> M;

    multiset<double> grade[10005];
    double t;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cin >> t;
            grade[i].insert(t);
        }
    }

    vector<double> ans;
    double tmp;
    for (int i = 0; i < N; i++)
    {
        tmp = accumulate(grade[i].begin(), grade[i].end(), 0);
        tmp -= *grade[i].begin();
        tmp -= *grade[i].rbegin();
        tmp /= grade[i].size() - 2;
        ans.push_back(tmp);
    }

    return 0;
}