//L2-020 功夫传人
#include <bits/stdc++.h>
using namespace std;

typedef struct Peo
{
    double power = 0;
    vector<int> Sons;
    bool flag = false;
}Peo;
Peo P[100005];
int main(void)
{
    int N, K, son;
    double Z, r;
    cin >> N >> Z >> r;
    for (int i = 0; i < N; i++)
    {
        cin >> K;
        if (K != 0)
        {
            for (int j = 0; j < K; j++)
            {
                cin >> son;
                P[i].Sons.push_back(son);
            }
        }
        else
        {
            P[i].flag = true;
            cin >> P[i].power;
        }
    }
    //注意特判祖师爷也是得道者的情况
    if (P[0].flag)
    {
        cout << (int)P[0].power * Z << endl;
        return 0;
    }
    double sumValue = 0;
    P[0].power = Z;
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        if (P[t].flag)
            sumValue += P[t].power;
        for (auto i : P[t].Sons)
        {
            if (!P[i].flag)
            {
                P[i].power = P[t].power * (1 - (0.01 * r));
                q.push(i);
            }
            else
            {
                P[i].power *= (P[t].power * (1 - (0.01 * r)));
                q.push(i);
            }
        }
    }
    printf("%d\n", (int)sumValue);

    return 0;
}