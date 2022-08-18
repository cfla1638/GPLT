#include <bits/stdc++.h>
using namespace std;

int P[10005];
int main()
{   
    int N, K, t;
    cin >> N;
    memset(P, -1, sizeof(P));
    for (int i = 0; i < N; i++)
    {
        cin >> K;
        for (int j = 0; j < K; j++)
        {
            cin >> t;
            P[t] = i;
        }
    }
    int maxf = 0;
    vector<string> maxpath;
    for (int i = 0; i < N; i++)
    {
        string path;
        int num = 1, t = i;
        path.push_back(t+48);
        while(P[t]!=-1)
        {
            path.push_back(P[t] + 48);
            num++;
            t = P[t];
        }
        if (maxf < num)
        {
            maxf = num;
            maxpath.clear();
            maxpath.push_back(path);
        }
        else if (maxf == num)
            maxpath.push_back(path);
    }
    for (auto &i : maxpath)
        reverse(i.begin(), i.end());
    if (maxpath.size() != 1)
        sort(maxpath.begin(), maxpath.end());
    cout << maxf << endl;
    for (size_t i = 0; i < maxpath[0].size(); i++)
        if (i+1!=maxpath[0].size())
            cout << maxpath[0][i] << " ";
        else
            cout << maxpath[0][i];
    return 0;
}

/*
这个人很牛逼
#include <bits/stdc++.h>
using namespace std;

vector<int> e[10010], temp, ans;
int n, maxx = -1;
bool book[10010];
int que[10010];

void dfs(int u, int k)
{
	if (k > maxx)//如果路径长度比现有长度更长
	{
		maxx = k;//更新最大长度
		ans = temp;//更新最大长度的序列
	}
	for (int i = 0; i < e[u].size(); i++)
	{
		temp.push_back(e[u][i]);//模拟每一步
		dfs(e[u][i], k + 1);
		temp.pop_back();//不要忘记pop出来
	}
	return;
}

int main(int argc, char const *argv[])
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		while (t--)
		{
			int x;
			cin >> x;
			book[x] = 1;
			e[i].push_back(x);
		}
		sort(e[i].begin(), e[i].end());//从小到大排序，这样如果能找到最大路径的话一定是最小序列
	}
	int flag;//病毒源头
	for (int i = 0; i < n; i++)
		if (book[i] == 0)
		{
			flag = i;
			break;
		}
	dfs(flag, 0);
	printf("%d\n", maxx + 1);
	printf("%d", flag);
	for (int i = 0; i < ans.size(); i++)
		printf(" %d", ans[i]);
	printf("\n");
	return 0;
}

*/