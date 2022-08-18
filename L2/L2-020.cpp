//L2-020 ¹¦·ò´«ÈË
#include <bits/stdc++.h>
using namespace std;
typedef struct Peo
{
    int master = -1;
    int power = 0;
    int gen = -1;
    bool flag = false;
}Peo;
Peo P[100005];
int GetGen(int i)
{
    if (P[i].master != -1)
    {
        if (P[P[i].master].gen != -1)
        {
            P[i].gen = P[P[i].master].gen + 1;
            return P[i].gen;
        }
        else
        {
            P[i].gen = GetGen(P[i].master);
            return P[i].gen;
        }
    }
}
int main(void)
{
    int N, Z, r, K;
    int son;
    cin >> N >> Z >> r;

    for (int i = 0; i < N; i++)
    {
        cin >> K;
        if (K != 0)
        {
            for (int j = 0; j < K; j++)
            {
                cin >> son;
                P[son].master = i;
            }
        }
        else
        {
            P[i].flag = true;
            cin >> P[i].power;
        }
    }
    P[0].gen = 0;
    for (int i = 0; i < N; i++)
        if (P[i].gen == -1)
            GetGen(i);

    int sumVal = 0;
    queue<int> Q;
    P[0].power = Z;
    Q.push(0);

    while (!Q.empty())
    {

    }

    return 0;
}
/*
10 18.0 1.00
3 2 3 5
1 9
1 4
1 7
0 7
2 6 1
1 8
0 9
0 4
0 3

*/