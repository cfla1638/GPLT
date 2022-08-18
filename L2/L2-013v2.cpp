//L2-013 红色警报 DFS版本
#include <bits/stdc++.h>
using namespace std;

const int MAX_V = 505;
set<int> G[MAX_V];
int known[MAX_V];

void DFS(int i)
{
    known[i] = 1;
    for (auto elem : G[i])
    {
        if (!known[elem])
        {
            known[elem] = 1;
            DFS(elem);
        }
    }
}

int main(void)
{
    int N, M, dead = 0;
    int cnkt = 0, tmpCnkt = 0;
    int u, v;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        G[u].insert(v);
        G[v].insert(u);
    }
    memset(known, 0, sizeof(known));
    for (int i = 0; i < N; i++)     //计算连通分量
    {
        if (!known[i])
        {
            cnkt++;
            DFS(i);
        }
    }
    int K; cin >> K;
    while (K--)
    {
        int t;
        tmpCnkt = 0;
        cin >> t;
        dead++;
        for (auto i : G[t])
            G[i].erase(t);
        G[t].clear();
        memset(known, 0, sizeof(known));
        for (int i = 0; i < N; i++)     //计算连通分量
        {
            if (!known[i])
            {
                tmpCnkt++;
                DFS(i);
            }
        }
        if (tmpCnkt > cnkt + 1)
            cout << "Red Alert: City " << t << " is lost!" << endl;
        else    
            cout << "City "<< t << " is lost." << endl;
        if (N - dead == 0)
            cout << "Game Over." << endl;
        cnkt = tmpCnkt;
    }
}