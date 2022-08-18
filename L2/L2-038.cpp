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
����˺�ţ��
#include <bits/stdc++.h>
using namespace std;

vector<int> e[10010], temp, ans;
int n, maxx = -1;
bool book[10010];
int que[10010];

void dfs(int u, int k)
{
	if (k > maxx)//���·�����ȱ����г��ȸ���
	{
		maxx = k;//������󳤶�
		ans = temp;//������󳤶ȵ�����
	}
	for (int i = 0; i < e[u].size(); i++)
	{
		temp.push_back(e[u][i]);//ģ��ÿһ��
		dfs(e[u][i], k + 1);
		temp.pop_back();//��Ҫ����pop����
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
		sort(e[i].begin(), e[i].end());//��С������������������ҵ����·���Ļ�һ������С����
	}
	int flag;//����Դͷ
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