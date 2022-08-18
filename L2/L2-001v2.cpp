//���������г�ʱ�Ĵ���
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

int N, M, S, D;
int G[505][505];            //�ڽӾ���

int rescueCount[505];       //ÿ����ľ�Ԯ������
int sumCount[505];          //���˵��ۼƵľ�Ԯ������
bool known[505];
array<int, 505> dist;
int path[505];
array<int, 505> roadCount;  //��¼��Դ�㵽�˵�����·������Ŀ
auto cmp = [](int a, int b){return dist[a] > dist[b];};
priority_queue<int, vector<int>, decltype(cmp)> heap(cmp);

void pathPrint(int v)
{
    if (path[v] != -2)
        pathPrint(path[v]);
    if (path[v] == -2)
        cout << v;
    else    
        cout << " " << v;
}

void Dijkstra()
{
    for(;;)
    {
        int minVertex = -1;
        while (!heap.empty())
        {
            if (!known[heap.top()])
            {
                minVertex = heap.top();
                heap.pop();
                break;
            }
            else
                heap.pop();
        }

        if (minVertex == -1)
            break;
        int w = 0;
        while (w < 505)
        {
            //���w��v������δ֪
            if (G[minVertex][w] < inf && !known[w] && w != minVertex)
            {
                if (dist[minVertex] + G[minVertex][w] <= dist[w])
                {   //������ȣ���Ԯ��������ԭ��Ԯ������
                    if (dist[minVertex] + G[minVertex][w] == dist[w] && sumCount[minVertex] + rescueCount[w] > sumCount[w])
                    {
                        roadCount[w] += roadCount[minVertex];
                        path[w] = minVertex;
                        sumCount[w] = sumCount[minVertex] + rescueCount[w];
                        heap.push(w);
                    }
                    else if (dist[minVertex] + G[minVertex][w] == dist[w] && sumCount[minVertex] + rescueCount[w] <= sumCount[w])
                    {
                        roadCount[w] += roadCount[minVertex];
                        continue;
                    }
                    else
                    {
                        dist[w] = dist[minVertex] + G[minVertex][w];
                        path[w] = minVertex;
                        sumCount[w] = sumCount[minVertex] + rescueCount[w];
                        roadCount[w] = roadCount[minVertex];
                        heap.push(w);
                    }
                }
            }
            w++;
        }
    }
}

int main(void)
{
    cin >> N >> M >> S >> D;

    for (int i = 0; i < N; i++)
        cin >> rescueCount[i];
    for (int i = 0; i < 505; i++)
        for (int j = 0; j < 505; j++)
            if (i == j)
                G[i][j] = 0;
            else
                G[i][j] = inf;
    for (int i = 0; i < M; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        G[s][d] = w;
        G[d][s] = w;
    }
    for (int i = 0; i < 505; i++)
    {
        sumCount[i] = rescueCount[i];
        known[i] = false;
        dist[i] = inf;
        path[i] = -1;   //���δ֪
        roadCount[i] = 0;
    }
    dist[S] = 0;
    path[S] = -2;   //���Դ��
    roadCount[S] = 1;
    heap.push(S);
    Dijkstra();

    cout << roadCount[D] << " " << sumCount[D] << endl;
    pathPrint(D);
    return 0;
}