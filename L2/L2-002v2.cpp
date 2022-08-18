//L2-002 链表去重 别人的思路，使用数组下标储存地址
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100005;

int main(void)
{
    int val[MAX], next[MAX], check[MAX] = {0};
    int path1[MAX], path2[MAX];
    int p1 = 0, p2 = 0;
    int iter, N;
    memset(next, -1, sizeof(next));
    memset(val, -1, sizeof(val));
    cin >> iter >> N;
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        cin >> val[t] >> next[t];
    }

    while (iter != -1)
    {
        if (!check[abs(val[iter])])
        {
            check[abs(val[iter])] = 1;
            path1[p1++] = iter;
        }
        else
        {
            path2[p2++] = iter;
        }
        iter = next[iter];
    }

    if (p1)
    {
        for (int i = 0; i < p1; i++)
        {
            if (i + 1 != p1)
            {
                printf("%05d", path1[i]);
                cout << " " << val[path1[i]] << " ";
                printf("%05d\n", path1[i + 1]);
            }
            else 
            {
                printf("%05d", path1[i]);
                cout << " " << val[path1[i]] << " " << -1 << endl;
            }  
        }
    }
    
    if (p2)
    {
        for (int i = 0; i < p2; i++)
        {
            if (i + 1 != p2)
            {
                printf("%05d", path2[i]);
                cout << " " << val[path2[i]] << " ";
                printf("%05d\n", path2[i + 1]);
            }
            else 
            {
                printf("%05d", path2[i]);
                cout << " " << val[path2[i]] << " " << -1 << endl;
            }  
        }
    }

    return 0;
}