//L2-017 人以群分
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int N, t;
    vector<int> s;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> t;
        s.push_back(t);
    }

    sort(s.begin(), s.end());

    if (N % 2 == 0)
    {
        int a, b;
        a = accumulate(s.begin(), s.begin() + N/2, 0);
        b = accumulate(s.begin() + N/2, s.end(), 0);
        cout << "Outgoing #: " << N/2 << endl;
        cout << "Introverted #: " << N/2 << endl;
        cout << "Diff = " << b - a << endl;
    }
    else
    {
        int a, b, c, d;
        a = accumulate(s.begin(), s.begin() + N/2, 0);
        b = accumulate(s.begin() + N/2, s.end(), 0);
        c = accumulate(s.begin(), s.begin() + N/2 + 1, 0);
        d = accumulate(s.begin() + N/2 + 1, s.end(), 0); 
        if (b-a > d-c)
        {
            cout << "Outgoing #: " << N/2 + 1 << endl;
            cout << "Introverted #: " << N/2 << endl;
            cout << "Diff = " << b - a << endl;
        }
        else
        {
            cout << "Outgoing #: " << N/2 << endl;
            cout << "Introverted #: " << N/2 + 1 << endl;
            cout << "Diff = " << d - c << endl;
        }
    }

    return 0;
}