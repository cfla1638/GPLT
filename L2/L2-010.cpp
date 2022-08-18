#include <bits/stdc++.h>
using namespace std;

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
    //��λ����
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

//��map�����ˣ���סfind���÷������ܻ�鲻ȫ
int G[105][105];
int main(void)
{
    inti(105);
    bool isbad;
    
    int N, M, K, p1, p2, status;
    cin >> N >> M >> K;
    for (int i = 1; i <= M; i++)
    {
        cin >> p1 >> p2 >> status;
        if (status == 1)
        {
            G[p1][p2] = G[p2][p1] = 1;
            unite(p1, p2);
        }
        else if (status == -1)
            G[p1][p2] = G[p2][p1] = -1;
    }
    while (K--)
    {
        cin >> p1 >> p2;

        if (G[p1][p2] == -1)    isbad = true;
        else isbad = false;

        if (isbad)   //������
        {
            if (same(p1,p2))
                cout << "OK but..." << endl;
            else
                cout << "No way" << endl;
        }
        else
        {
            if (same(p1,p2))
                cout << "No problem" << endl;
            else 
                cout << "OK" << endl;
        }
    }
    return 0;
}