#include <bits/stdc++.h>
using namespace std;
struct Serial
{
    int f = 1;
    int count = 0;
    array<int, 101> arr;
};
ostream& operator<<(ostream &os, const Serial &a)
{
    for (int i = 0; i < a.count; i++)
        if (i + 1 != a.count)
            os << a.arr[i] << " ";
        else
            os << a.arr[i];
    return os;
}
bool operator==(const Serial &b, const Serial &a)
{
    for (int i = 0; i < b.count; i++)
        if (b.arr[i] != a.arr[i])
            return false;
    return true;
}
bool operator!=(const Serial &b, const Serial &a)
{
    return !(b == a);
}
//如果两个对象的<结果为false，则两个元素被视为相等
bool operator<(const Serial &b, const Serial &a)
{
    for (int i = 0; i < b.count; i++)
    {
        if (b.arr[i] < a.arr[i])
            return true;
        else if (b.arr[i] > a.arr[i])
            return false;
    }
    return false;
}
int main()
{   
    int N, M;
    set<Serial> D;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        Serial t;
        t.f = -1;
        t.count = M;
        for (int j = 0; j < M; j++)
            cin >> t.arr[j];
        set<Serial>::iterator iter = D.find(t);
        if (iter != D.end())
        {
            Serial tmp;
            tmp.arr = iter->arr;
            tmp.count = iter->count;
            tmp.f = iter->f + 1;
            D.erase(iter);
            D.insert(tmp);
        }
        else
        {
            t.f = 1;
            D.insert(t);
        }
    }
    vector<Serial> v;
    for (auto i : D)
        v.push_back(i);
    auto cmp = [](Serial a, Serial b)
    {
        if (a.f != b.f)
            return a.f > b.f;
        else
            return a < b;
    };
    sort(v.begin(), v.end(), cmp);
    cout << D.size() << endl;
    for (auto i : v)
        cout << i.f << " " << i <<endl;
    return 0;
}