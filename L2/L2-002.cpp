//L2-002 链表去重
#include<bits/stdc++.h>
using namespace std;

const int MAX = 100005;
string start = "-1";
int N;
string adr[MAX];
int val[MAX];
string Next[MAX];
vector<int> existVal;
string exclude = "-1";
string rearExclude = "-1";
string pre = "-1";

int pos(string _adr)
{
    for (int i = 0; i < N; i++)
        if (adr[i] == _adr)
            return i;
    return -1;
}

static void Debug_arr(string *arr,int n)
{
    for (int i = 0; i < n; i++)
       cout << "arr[" << i << "] = " << arr[i] << endl;
}

int main(void)
{
    cin >> start >> N;
    for (int i = 0; i < N; i++)
        cin >> adr[i] >> val[i] >> Next[i];
    string iter = start;
    while (iter != "-1")
    {
        //不存在
        if (count(existVal.begin(), existVal.end(), abs(val[pos(iter)])) == 0)
        {
            existVal.push_back(abs(val[pos(iter)]));
            pre = iter;
            iter = Next[pos(iter)];     //迭代
        }
        else
        {
            string originNext = Next[pos(iter)];
            //第一个要被排除的数据
            if (exclude == "-1")
            {
                exclude = iter;
                Next[pos(pre)] = originNext;
                Next[pos(iter)] = "-1";
                rearExclude = iter;
            }
            else
            {
                Next[pos(rearExclude)] = iter;
                Next[pos(iter)] = "-1";
                Next[pos(pre)] = originNext;
                rearExclude =  iter;
            }
            iter = originNext;
            //前驱节点不需要更新
        }
    }
    //Debug_arr(Next, 5);
    
    iter = start;
    for(;;)
    {
        //cout << "pos(iter) = " <<pos(iter) << endl;
        cout << adr[pos(iter)] << " " << val[pos(iter)] <<" " << Next[pos(iter)] << endl;
        iter = Next[pos(iter)];
        if (iter == "-1")
            break;
    }
    
    iter = exclude;
    for(;;)
    {
        //system("pause");
        cout << adr[pos(iter)] << " " << val[pos(iter)] <<" " << Next[pos(iter)] << endl;
        iter = Next[pos(iter)];
        if (iter == "-1")
            break;
    }
    return 0;
}