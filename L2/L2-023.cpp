//L2-023 图着色问题
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> G;
int color[505];

int main(void)
{
    int V, E, K, N;
    cin >> V >> E >> K;
    int u, v;
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v;
        G.push_back(pair<int, int>(u,v));
    }
    cin >> N; 
    while (N--)
    {
        set<int> colorSet;
        bool notOk = false;
        int c;
        for (int i = 1; i <= V; i++)
        {
            cin >> c;
            if (c > V || c <= 0)
                notOk = true;
            colorSet.insert(c);
            color[i] = c;
        }
        if (colorSet.size() != K)
            notOk = true;
        
        for (auto i : G)
        {
            if (color[i.first] == color[i.second])
                notOk = true;
        }

        if (notOk)
        {
            cout << "No\n";
        }
        else
        {
            cout << "Yes\n";
        }
    }
    return 0;
}