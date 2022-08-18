//L2-025 分而治之
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    array<vector<int>, 10005> G;
    int N, M, K, Np;
    cin >> N >> M;
    int u, v;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    cin >> K;
    while (K--)
    {
        array<bool, 10005> alive;
        alive.fill(true);
        array<vector<int>, 10005> g(G);
        cin >> Np;
        while (Np--)
        {
            cin >> v;
            alive[v] = false;
            for (auto i : g[v])
            {
                for (auto j = g[i].begin(); j != g[i].end(); j++)
                    if (*j == v)
                    {
                        g[i].erase(j);
                        break;
                    }
            }
            g[v].clear();
        }
        bool flag = false;
        for (int i = 1; i <= N; i++)
        {
            if (alive[i] && !g[i].empty())
                flag = true;
        }
        if (flag)
            cout << "NO\n";
        else    
            cout << "YES\n";
    }

    return 0;
}