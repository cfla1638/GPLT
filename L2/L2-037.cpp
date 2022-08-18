#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M, S;
    cin >> N >> M >> S;
    stack<char> vol;
    string orbit[105];
    string line;
    for (int i = 1; i <= N; i++)
    {
        cin >> orbit[i];
    }
    int cmd;
    cin >> cmd;
    while(cmd != -1)
    {
        if (cmd == 0)
        {
            if (!vol.empty())
            {
                line.push_back(vol.top());
                vol.pop();
            }
        }
        else
        {
            if(!orbit[cmd].empty())
            {
                if (vol.size() >= S)
                {
                    line.push_back(vol.top());
                    vol.pop();
                    vol.push(orbit[cmd].front());
                    orbit[cmd].erase(orbit[cmd].begin());
                }
                else
                {
                    vol.push(orbit[cmd].front());
                    orbit[cmd].erase(orbit[cmd].begin());
                }
            }
        }
        cin >> cmd;
    }
    cout << line;
    return 0;
}