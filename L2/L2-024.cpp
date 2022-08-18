//L2-024 ����
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 10005

int par[MAX_N];     //����
int Rank[MAX_N];    //���ĸ߶�

//��ʼ��n�������ļ��ϣ�ÿ�����ϵĸ߶���0
void inti(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = i;
        Rank[i] = 0;
    }
}

//��ѯ���ĸ�
int find(int x)
{
    if (par[x] == x)
        return x;
    else
       //�˲������Կ���д��û�и�ֵ����return find(par[x])
       //���˸�ֵ�����һ��·��ѹ�������ã��ڻ��ݵ����ڵ�Ĺ����У����еĽ��ĸ�ֱ��ָ���˸�
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

int main(void)
{
    inti(MAX_N);
    int N, K, Q, p;
    set<int> people;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> K;
        int pre = -1;
        for (int i = 0; i < K; i++)
        {
            cin >> p;
            people.insert(p);
            if (pre != -1)
                unite(pre, p);
            else pre = p;
        }
    }

    set<int> root;
    for (auto i : people)
        root.insert(find(i));
    cout << people.size() << " " << root.size() << '\n';
    cin >> Q;
    while (Q--)
    {
        int p1, p2;
        cin >> p1 >> p2;
        if (same(p1, p2))
            cout << "Y\n";
        else
            cout << "N\n";
    }

    return 0;
}