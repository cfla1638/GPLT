//三个测试点没过的shabby代码
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100005

int par[MAX_N];     //父亲
int Rank[MAX_N];    //树的高度

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
    string firstName;
    string lastName;
    int sex;
    int father;
    bool tag;
}Peo;
Peo P[100005];
int N = 0;
int pos(string firstName)
{
    for (int i = 0; i < N; i++)
        if (P[i].firstName == firstName)
            return i;
    return -1;
}

int main(void)
{
    string first, last;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> first >> last;
        P[i].firstName = first;
        if (last.back() == 'm')
        {
            last.pop_back();
            P[i].lastName = last;
            P[i].sex = 1;
            P[i].tag = 0;
        }
        else if (last.back() == 'f')
        {
            last.pop_back();
            P[i].lastName = last;
            P[i].sex = -1;
            P[i].tag = 0;
        }
        else if (last.size() > 4 && last.substr(last.size() - 4, 4) == "sson")
        {
            for (int j = 0; j < 4; j++)
                last.pop_back();
            P[i].lastName = last;
            P[i].sex = 1;
            P[i].tag = 1;
        }
        else if (last.size() > 7 && last.substr(last.size() - 7, 7) == "sdottir")
        {
            for (int j = 0; j < 7; j++)
                last.pop_back();
            P[i].lastName = last;
            P[i].sex = -1;
            P[i].tag = 1;  
        }
    }

    for (int i = 0; i < N; i++)
    {
        bool flag = false;
        for (int j = 0; j < N; j++)
        {
            if (P[i].lastName == P[j].firstName)
            {
                P[i].father = j;
                flag = true;
                break;
            }
        }
        if (!flag)
            P[i].father = -1;
    }

    /*
    for (int i = 0; i < N; i++)
    {
        cout << "---" << i << "---" << endl;
        cout << P[i].firstName << " " << P[i].lastName << endl;
        cout << P[i].sex << " " << P[i].tag << endl;
    }
    */

    int M;
    cin >> M;

    while (M--)
    {
        string ffirst, flast, sfirst, slast;
        cin >> ffirst >> flast >> sfirst >> slast;
        if (pos(ffirst) == -1 || pos(sfirst) == -1)
            cout << "NA\n";
        else if (P[pos(ffirst)].sex == P[pos(sfirst)].sex)
            cout << "Whatever\n";
        else if (P[pos(ffirst)].tag == 0 || P[pos(sfirst)].tag == 0)
            cout << "Yes\n";
        else
        {
            inti(N);
            queue<pair<int, int>> q;
            q.push(pair<int, int>(pos(ffirst), 1));
            while (!q.empty())
            {
                auto t = q.front();
                q.pop();

                if (t.second >= 4)
                    break;
                
                if (P[t.first].father != -1)    
                {
                    unite(t.first, P[t.first].father);
                    q.push(pair<int, int>(P[t.first].father, t.second + 1));
                    //cout << t.first << " " << P[t.first].father << endl;
                }
            }
            queue<pair<int, int> > empty;
            q.swap(empty);
            q.push(pair<int, int>(pos(sfirst), 1));
            while (!q.empty())
            {
                auto t = q.front();
                q.pop();
                
                if (t.second >= 4)
                    break;
                //cout << t.first << " beifen:" << t.second << endl;
                if (P[t.first].father != -1)    
                {
                    unite(t.first, P[t.first].father);
                    q.push(pair<int, int>(P[t.first].father, t.second + 1));
                    //cout << t.first << " " << P[t.first].father << endl;
                }
            }
            if (!same(pos(ffirst), pos(sfirst)))
                cout << "Yes\n";
            else 
                cout << "No\n";
        }
    }
    return 0;
}