#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 +7;

int G[300][300];

int main(void)
{
    int num = 0, N, M;
    cin >> N >> M;
    
    for (int i = 0; i < 300; i++)
        for (int j = 0; j < 300; j++)
            G[i][j] = inf;
    
    int u, v, w;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v >> w;
        G[u][v] = w;
        G[v][u] = w;
    }

    int K, n;
    int minfee = inf, cnt = 0, xuhao;
    vector<int> sq;
    cin >> K;
    for (int i = 1; i <= K; i++)
    {
        sq.clear();
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            int t; cin >> t;
            sq.push_back(t);
        }
        if (n != N)
            continue;
        bool f = false;
        for (size_t j = 0; j < sq.size(); j++)
        {
            if (count(sq.begin(), sq.end(), sq[j]) != 1)
                f = true;
        }
        if (f)  continue;
        int fee = 0;
        int pre = 0;
        sq.push_back(0);
        f = false;
        for (size_t j = 0; j < sq.size(); j++)
        {
            if (G[pre][sq[j]] != inf)
            {
                fee += G[pre][sq[j]];
                pre = sq[j];
            }
            else
            {
                f = true;
                break;
            }
        }
        if (f) continue;
        else cnt++;
        if (fee < minfee)
        {
            minfee = fee;
            xuhao = i;
        }
    }
    cout << cnt << endl;
    cout << xuhao << " " << minfee << endl;
    return 0;
}