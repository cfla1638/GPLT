#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    while (k--)
    {
        int t = 1, f = 1;
        stack<int> s;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x == t)
            { // x��ǡ����Ҫ��
                t++;
                while (!s.empty() && s.top() == t)
                { // s.top()�ǲ�����װ
                    s.pop();
                    t++;
                }
            }
            else
            { //װ���˾�s.push()
                s.push(x);
                if (s.size() > m)
                    f = 0;
            }
        }
        if (s.size() > 0)
            f = 0; //û�н���ɫȫ��װ��
        cout << (f ? "YES" : "NO") << endl;
    }
    return 0;
}