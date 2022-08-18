#include <bits/stdc++.h>
using namespace std;

int heap[1005], sz = 0;
void push(int x)
{
    int i = sz++;   //将x放在数组最后
    while (i > 0)   //当未迭代到根
    {
        int p = (i - 1) / 2;
        if (heap[p] <= x)   break;
        heap[i] = heap[p];
        i = p;
    }
    heap[i] = x;
}

int pos(int x)
{
    int i;
    for (i = 0; i < sz; i++)
        if (x == heap[i]) break;
    return i;
}

int father(int x)
{
    if (x != 0)
        return (x - 1) / 2;
    else
        return 1004;
}

int main(void)
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int t; 
        cin >> t; 
        push(t);
    }
    getchar();
    while(M--)
    {
        string line;
        getline(cin, line);
        stringstream stream(line);
        int d1, d2 = -1, Case = -1;
        string tmp;
        stream >> d1;
        while (stream >> tmp)
        {
            if (isdigit(tmp.c_str()[0]))
                d2 = atoi(tmp.c_str());
            else if (tmp == "root")
                Case = 1;
            else if (tmp == "siblings")
                Case = 2;
            else if (tmp == "parent")
                Case = 3;
            else if (tmp == "child")
                Case = 4;
        }
        switch (Case)
        {
            case 1: 
                if (pos(d1) == 0)
                    cout << "T" << endl;
                else 
                    cout << "F" << endl;
                break;
            case 2:
                if (d1 == d2)
                    cout << "F" << endl;
                else if (pos(d1) == 0 || pos(d2) == 0)
                    cout << "F" << endl;
                else if (father(pos(d1)) == father(pos(d2)) )
                    cout << "T" << endl;
                else 
                    cout << "F" << endl;
                break;
            case 3 :
                if (d1 == d2)
                    cout << "F" << endl;
                else if (father(pos(d2)) == pos(d1))
                    cout << "T" << endl;
                else 
                    cout << "F" << endl;
                break;
            case 4:
                if (d1 == d2)
                    cout << "F" << endl;
                else if (father(pos(d1)) == pos(d2))
                    cout << "T" << endl;
                else 
                    cout << "F" << endl;
                break;
        }
    }
}