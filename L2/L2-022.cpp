//L2-022 ÷ÿ≈≈¡¥±Ì
#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    int val = 0;
    int next = -1;
}node;

node ls[100005];

int main(void)
{
    int begin, N, t;
    cin >> begin >> N;
    deque<int> dq;
    for (int i = 0; i < N; i++)
    {
        cin >> t;
        cin >> ls[t].val;
        cin >> ls[t].next;
    }
    dq.push_back(begin);
    t = ls[begin].next;
    while (t != -1)
    {
        dq.push_back(t);
        t = ls[t].next;
    }
    vector<int> vec;
    while (!dq.empty())
    {
        if (!dq.empty())    
        {
            vec.push_back(dq.back());
            dq.pop_back();
        }
        if (!dq.empty())    
        {
            vec.push_back(dq.front());
            dq.pop_front();
        }
    }
    if (!vec.empty())
    {
        //cout << vec[0] << " ";
        printf("%05d ", vec[0]);
        cout << ls[vec[0]].val << " ";
        for (vector<int>::size_type i = 1; i < vec.size(); i++)
        {
            printf("%05d\n%05d %d ", vec[i], vec[i], ls[vec[i]].val);
            //cout << vec[i] << endl << vec[i] << " " << ls[vec[i]].val << " ";
        }
        cout << -1 << endl;
        
    }


    return 0;
}