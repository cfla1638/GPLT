//≤‚ ‘µ„4 ¥ÌŒÛ
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int A, B;
    vector<int> happy;
    map<int, int> mp;
    cin >> A >> B;

    for (int i = A; i <= B; i++)
    {
        int t = i;
        vector<int> repeat;
        int freq = 0;
        while (t != 1 && t > 0)
        {
            freq++;
            
            string s = to_string(t);
            t = 0;
            for (auto c : s)
                t += (c - 48) * (c - 48);
            vector<int>::iterator iter;
            if ((iter = find(happy.begin(), happy.end(), t)) != happy.end())
            {
                mp.erase(t);
                happy.erase(iter);
            }
            if (count(repeat.begin(), repeat.end(), t) == 0)
                repeat.push_back(t);
            else
                break;
        }
        if (t == 1)
        {
            happy.push_back(i);
            mp[i] = freq;
        }
    }

    for (auto i : happy)
    {
        bool f = true;
        for (int j = 2; j <= (int)sqrt(i); j++)
            if (i % j == 0) f = false;
        if (f) mp[i] *= 2;
    }

    if (happy.empty())
        cout << "SAD" << endl;
    else
    {
        sort(happy.begin(), happy.end());
        for (auto i : happy)
        {
            cout << i <<  " "<< mp[i] <<endl;
        }
    }
    return 0;
}