//ʹ�ò��鼯
#include <bits/stdc++.h>
using namespace std;

//���鼯����
#define MAX_N 100005
//��һ��Ԫ�صĸ������Լ�ʱ����Ԫ��Ϊ�ü��ϵĸ��ڵ㣬���ж��Ƿ�Ϊ���ڵ������ʱpar[i] = i

//������ı�Ŵ���ÿ��Ԫ��
int par[MAX_N];     //����
int Rank[MAX_N];    //���ĸ߶�

//��ʼ��n�������ļ��ϣ�ÿ�����ϵĸ߶���0
void inti(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = i;
    }
    memset(Rank, 0, sizeof(Rank));
}

//��ѯ���ĸ�
int find(int x)
{
    if (par[x] == x)
        return x;
    else
       //�˲������Կ���д��û�и�ֵ����return find(par[x])
       //���˸�ֵ�����һ��·��ѹ�������ã��ڻ��ݵ����ڵ�Ĺ����У����еĽ��ĸ�ֱ��ָ���˸�
        return par[x] = find(par[x]);
}

void unite(int x, int y)
{
    //��λ����
    x = find(x);
    y = find(y);
    if (x == y) return ;

    if (Rank[x] < Rank[y])
        par[x] = y;
    else
    {
        par[y] = x;
        if (Rank[x] == Rank[y])     //�����ȵĻ��������¼��ϵĸ߶�
            Rank[x]++;
    }
}

bool same(int x, int y)
{
    return find(x) == find(y);
}


typedef struct
{
	int father = -1;
	int mother = -1;
	char sex;
} Peo; 

int N, K, id;
Peo P[100005];


int main(void)
{	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> id;
		cin >> P[id].sex >> P[id].father >> P[id].mother;
        P[P[id].father].sex = 'M';
        P[P[id].mother].sex = 'F';
	}
	
	int a, b;
	cin >> K;
	while (K--)
	{
		cin >> a >> b;
		if (P[a].sex == P[b].sex)
			cout << "Never Mind\n";
		else
		{
			inti(MAX_N);
            queue<pair<int, int> > q;
            q.push(pair<int, int>(a, 1));
            while (!q.empty())
            {
                auto t = q.front();
                q.pop();

                if (t.second >= 5)
                    break;
                
                if (P[t.first].father != -1)    
                {
                    unite(t.first, P[t.first].father);
                    q.push(pair<int, int>(P[t.first].father, t.second + 1));
                    //cout << t.first << " " << P[t.first].father << endl;
                }
                if (P[t.first].mother != -1)
                {
                    unite(t.first, P[t.first].mother);
                    q.push(pair<int, int>(P[t.first].mother, t.second + 1));
                    //cout << t.first << " " << P[t.first].mother << endl;
                }
            }
            queue<pair<int, int> > empty;
            q.swap(empty);
            q.push(pair<int, int>(b, 1));
            while (!q.empty())
            {
                auto t = q.front();
                q.pop();
                
                if (t.second >= 5)
                    break;
                //cout << t.first << " beifen:" << t.second << endl;
                if (P[t.first].father != -1)    
                {
                    unite(t.first, P[t.first].father);
                    q.push(pair<int, int>(P[t.first].father, t.second + 1));
                    //cout << t.first << " " << P[t.first].father << endl;
                }
                if (P[t.first].mother != -1)
                {
                    unite(t.first, P[t.first].mother);
                    q.push(pair<int, int>(P[t.first].mother, t.second + 1));
                    //cout << t.first << " " << P[t.first].mother << endl;
                }
            }

            if (!same(a, b))
                cout << "Yes" << endl;
            else 
                cout << "No" << endl;

		}
	}
	
	
	return 0;
}