//使用并查集
#include <bits/stdc++.h>
using namespace std;

//并查集代码
#define MAX_N 100005
//当一个元素的父亲是自己时，此元素为该集合的根节点，即判断是否为根节点的条件时par[i] = i

//用数组的编号储存每个元素
int par[MAX_N];     //父亲
int Rank[MAX_N];    //树的高度

//初始化n个独立的集合，每个集合的高度是0
void inti(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = i;
    }
    memset(Rank, 0, sizeof(Rank));
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


typedef struct
{
	int father = -1;
	int mother = -1;
	char sex;
} Peo; 

int N, K, id;
Peo P[100005];


int main(void)
{	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> id;
		cin >> P[id].sex >> P[id].father >> P[id].mother;
        P[P[id].father].sex = 'M';
        P[P[id].mother].sex = 'F';
	}
	
	int a, b;
	cin >> K;
	while (K--)
	{
		cin >> a >> b;
		if (P[a].sex == P[b].sex)
			cout << "Never Mind\n";
		else
		{
			inti(MAX_N);
            queue<pair<int, int> > q;
            q.push(pair<int, int>(a, 1));
            while (!q.empty())
            {
                auto t = q.front();
                q.pop();

                if (t.second >= 5)
                    break;
                
                if (P[t.first].father != -1)    
                {
                    unite(t.first, P[t.first].father);
                    q.push(pair<int, int>(P[t.first].father, t.second + 1));
                    //cout << t.first << " " << P[t.first].father << endl;
                }
                if (P[t.first].mother != -1)
                {
                    unite(t.first, P[t.first].mother);
                    q.push(pair<int, int>(P[t.first].mother, t.second + 1));
                    //cout << t.first << " " << P[t.first].mother << endl;
                }
            }
            queue<pair<int, int> > empty;
            q.swap(empty);
            q.push(pair<int, int>(b, 1));
            while (!q.empty())
            {
                auto t = q.front();
                q.pop();
                
                if (t.second >= 5)
                    break;
                //cout << t.first << " beifen:" << t.second << endl;
                if (P[t.first].father != -1)    
                {
                    unite(t.first, P[t.first].father);
                    q.push(pair<int, int>(P[t.first].father, t.second + 1));
                    //cout << t.first << " " << P[t.first].father << endl;
                }
                if (P[t.first].mother != -1)
                {
                    unite(t.first, P[t.first].mother);
                    q.push(pair<int, int>(P[t.first].mother, t.second + 1));
                    //cout << t.first << " " << P[t.first].mother << endl;
                }
            }

            if (!same(a, b))
                cout << "Yes" << endl;
            else 
                cout << "No" << endl;

		}
	}
	
	
	return 0;
}