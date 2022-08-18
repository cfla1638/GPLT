#include <bits/stdc++.h>
using namespace std;

const int MAX_NUM = 505;
const int inf = 1e9+7;

vector<pair<int, int>> G[MAX_NUM];
int path[MAX_NUM];
array<int, MAX_NUM> dist;
int road[MAX_NUM];
int peop[MAX_NUM];
int vis[MAX_NUM];
int peoCount[MAX_NUM];

int main(void)
{
    int N, M, S, D;

    cin >> N >> M >> S >> D;
    for (int i = 0; i < N; i++)
        cin >> peoCount[i];
    
    int s, d, w;
    for (int i = 0; i < M; i++)
    {
        cin >> s >> d >> w;
        G[s].push_back(pair<int, int>(d, w));
        G[d].push_back(pair<int, int>(s, w));
    }

    memset(path, -1, sizeof(path));
    dist.fill(inf);
    dist[S] = 0;
    peop[S] = peoCount[S];
    road[S] = 1;

    auto cmp = [](int a, int b) {return dist[a] > dist[b];};
    priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
    q.push(S);

    for (;;)
    {
        int minVertex = -1;

        while (!q.empty())
        {
            if (vis[q.top()])
            {
                q.pop();
                continue;
            }
            else
            {
                minVertex = q.top();
                q.pop();
                break;
            }
        }

        if (minVertex == -1)
            break;

        vis[minVertex] = 1;
        for (auto adj : G[minVertex])
        {
            if (!vis[adj.first])
            {
                if (dist[minVertex] + adj.second < dist[adj.first])
                {
                    road[adj.first] = road[minVertex];
                    path[adj.first] = minVertex;
                    peop[adj.first] = peop[minVertex] + peoCount[adj.first];
                    dist[adj.first] = dist[minVertex] + adj.second;
                }
                else if (dist[minVertex] + adj.second == dist[adj.first])
                {
                    road[adj.first] += road[minVertex];
                    if (peop[minVertex] + peoCount[adj.first] >= peop[adj.first])
                    {
                        path[adj.first] = minVertex;
                        peop[adj.first] = peop[minVertex] + peoCount[adj.first];
                    }
                    else
                    {

                    }
                }
                q.push(adj.first);
            }
        }
    }

    cout << road[D] << " " << peop[D] << endl;
    vector<int> pa;
    int t = D;
    while (path[t] != -1)
    {
        pa.push_back(t);
        t = path[t];
    }
    cout << S;
    for (auto i = pa.rbegin(); i != pa.rend(); i++)
    {
        cout << " " << *i;
    }

    return 0;
}