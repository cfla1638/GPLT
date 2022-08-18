//L2-013 ��ɫ���� ���鼯�汾
#include <bits/stdc++.h>
using namespace std;

const int MAX_V = 505;
set<int> G[MAX_V];

//���鼯����
#define MAX_N 1000
int par[MAX_N];     //����
int Rank[MAX_N];    //���ĸ߶�
void inti(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = i;
        Rank[i] = 0;
    }
}
int find(int x)
{
    if (par[x] == x)
        return x;
    else
        return par[x] = find(par[x]);
}
void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y) return ;

    if (Rank[x] < Rank[y])
        par[x] = y;
    else
    {
        par[y] = x;
        if (Rank[x] == Rank[y])     //�����ȵĻ��������¼��ϵĸ߶�
            Rank[x]++;
    }
}
bool same(int x, int y)
{
    return find(x) == find(y);
}


int main(void)
{
    int N, M, dead = 0;
    int cnkt = 0, tmpCnkt = 0;
    int u, v;
    set<int> ex;
    cin >> N >> M;
    inti(N);
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        unite(u, v);
        G[u].insert(v);
        G[v].insert(u);
    }
    for (int i = 0; i < N; i++)     //������ͨ����
    {
        int root;
        root = find(i);
        if (ex.count(root) == 0)
        {
            ex.insert(root);
            cnkt++;
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

        inti(N);
        for (int i = 0; i < N; i++)
        {
            for (auto j : G[i])
                unite(i, j);
        }

        ex.clear();     //���沢�鼯���ڵ�
        for (int i = 0; i < N; i++)     //������ͨ����
        {
            int root;
            root = find(i);
            if (ex.count(root) == 0)
            {
                ex.insert(root);
                tmpCnkt++;
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