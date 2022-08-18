//带佬解法
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int MAX_N = 1e5 + 5;
struct Per
{
    bool sex;
    int id;
};
map<string, Per> mps1;
int pre[MAX_N];
string s1, s2, s3, s4;
void init()
{
    for (int i = 1; i < MAX_N; ++i)
        pre[i] = i;
}
int Find(int x)
{
    int rt = pre[x];
    if (pre[x] != x)
        rt = Find(pre[x]);
    return rt;
}
bool judge(int x, int y)
{
    /*
        两人存在公共祖先的情况下
        判断这个共同祖先是否在五代以内
    */
    int ret = 1;
    while (x != pre[x] && y != pre[y])
    {
        x = pre[x];
        y = pre[y];
        ++ret;
        if (ret == 5)
            return true; //不在五代以内
        if (x == y)
            return false; //五代以内存在共同祖先
    }
    return false;
    /*
        能够跳出while循环
        说明某个人无五代祖先
        但是已经判断出两人存在公共祖先
        说明两人五代以内存在公共祖先,返回false
    */
}
int main()
{
    ios::sync_with_stdio(false);
    init();
    int n;
    cin >> n;
    int cnt = 0;
    vector<vector<string>> in(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> s1 >> s2;
        mps1[s1].id = ++cnt;
        in[i].push_back(s1);
        in[i].push_back(s2);
    }
    for (int i = 0; i < n; ++i)
    {
        s1 = in[i][0], s2 = in[i][1];
        if (s2.length() > 4 && s2.substr(s2.length() - 4, 4) == "sson")
        {
            pre[mps1[s1].id] = mps1[s2.substr(0, s2.length() - 4)].id;
            mps1[s1].sex = true;
        }
        else if (s2.length() > 7 && s2.substr(s2.length() - 7, 7) == "sdottir")
        {
            pre[mps1[s1].id] = mps1[s2.substr(0, s2.length() - 7)].id;
            mps1[s1].sex = false;
        }
        else
        {
            if (s2.back() == 'm')
                mps1[s1].sex = true;
            else
                mps1[s1].sex = false;
        }
    }
    int m;
    cin >> m;
    while (m--)
    {
        cin >> s1 >> s2 >> s3 >> s4;
        if (!mps1[s1].id || !mps1[s3].id)
            printf("NA\n");
        else if (mps1[s1].sex == mps1[s3].sex)
            printf("Whatever\n");
        else if (Find(mps1[s1].id) != Find(mps1[s3].id))    //没有祖先
            printf("Yes\n");
        else if (judge(mps1[s1].id, mps1[s3].id))           //祖先不在五代以内
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}