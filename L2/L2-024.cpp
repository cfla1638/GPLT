//L2-024 部落
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 10005

int par[MAX_N];     //父亲
int Rank[MAX_N];    //树的高度

//初始化n个独立的集合，每个集合的高度是0
void inti(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = i;
        Rank[i] = 0;
    }
}

//查询树的根
int find(int x)
{
    if (par[x] == x)
        return x;
    else
       //此步本可以可以写成没有赋值语句的return find(par[x])
       //有了赋值语句起到一个路径压缩的作用，在回溯到根节点的过程中，所有的结点的根直接指向了根
        return par[x] = find(par[x]);
}

void unite(int x, int y)
{
    //定位到根
    x = find(x);
    y = find(y);
    if (x == y) return ;

    if (Rank[x] < Rank[y])
        par[x] = y;
    else
    {
        par[y] = x;
        if (Rank[x] == Rank[y])     //如果相等的话，更新新集合的高度
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