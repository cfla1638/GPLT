//L1-071 前世档案
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int N, M;   //N回答问题数， M玩家人数

    cin >> N >> M;
    getchar();

    for (int i = 0; i < M; i++)
    {
        char input;
        int ans = 1;
        
        while ((input = getchar()) != '\n')
        {
            if (input == 'y')
                ans *=2;
            if (input == 'n')
                ans = ans * 2 + 1;
        }

        ans -= (int)pow(2, N) - 1;
        cout << ans << endl;
    }
    return 0;
}