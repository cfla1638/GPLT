//L2-031 …Ó»Îª¢—®
#include <bits/stdc++.h>
using namespace std;

typedef struct door
{
    vector<int> sons;
    int gen = 0;
}door;

door D[100005];
int visit[100005];

int main(void)
{
    int N, K;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> K;
        for (int j = 0; j < K; j++)
        {
            int son;
            cin >> son;
            visit[son] = 1;
            D[i].sons.push_back(son);
        }
    }

    int in;
    for (int i = 1; i <= N; i++)
        if (!visit[i])
            in = i;
    stack<int> s;
    s.push(in);
    D[in].gen = 1;
    int last = in;
    while (!s.empty())
    {
        int t = s.top(); s.pop();

        for (auto i : D[t].sons)
        {
            s.push(i);
            D[i].gen = D[t].gen + 1;
        }
        last = t;
    }
    int max = -1;
    for (int i = 1; i <= N; i++)
    {
        if (D[i].gen > max)
        {    
            max = D[i].gen;
            last = i;
        }
    }
    cout << last << endl;

}