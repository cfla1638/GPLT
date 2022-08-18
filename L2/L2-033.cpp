//L2-033 简单计算器
//注意所有的计算都只取结果的整数部分。！！！！！！！！！！！！！！！！！！！！！！！！
//怎么还会有卡这个点的，Kora！
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    stack<int> s1;
    stack<char> s2;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        s1.push(t);
    }
    for (int i = 0; i < N - 1; i++)
    {
        char t;
        cin >> t;
        s2.push(t);
    }
    while (!s1.empty() && !s2.empty())
    {
        int n1, n2, ans;
        char op;
        n1 = s1.top(); s1.pop();
        n2 = s1.top(); s1.pop();
        op = s2.top(); s2.pop();
        switch (op)
        {
        case '+':
            ans = n2 + n1;
            break;
        case '-':
            ans = n2 - n1;
            break;
        case '*':
            ans = n2 * n1;
            break;
        case '/':
            if (n1 != 0)
                ans = n2 / n1;
            else
            {
                printf("ERROR: %d/0\n", (int)n2);
                return 0;
            }
            break;
        }
        s1.push(ans);
    }
    cout << (int)s1.top() << endl;
    return 0;
}