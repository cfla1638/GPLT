//直接查找所有祖先
#include <bits/stdc++.h>
using namespace std;

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
            set<int> A, B;
            queue<pair<int, int>> q;
            q.push(pair<int, int>(a, 1));
            while (!q.empty())
            {
                auto t = q.front(); q.pop();
                if (t.second >= 5)
                    break;
                if (P[t.first].father != -1)
                {
                    A.insert(P[t.first].father);
                    q.push(pair<int, int>(P[t.first].father, t.second + 1));
                }
                if (P[t.first].mother != -1)
                {
                    A.insert(P[t.first].mother);
                    q.push(pair<int, int>(P[t.first].mother, t.second + 1));
                }
            }
            queue<pair<int, int> > empty;
            q.swap(empty);
            q.push(pair<int, int>(b, 1));
            while (!q.empty())
            {
                auto t = q.front(); q.pop();
                if (t.second >= 5)
                    break;
                if (P[t.first].father != -1)
                {
                    B.insert(P[t.first].father);
                    q.push(pair<int, int>(P[t.first].father, t.second + 1));
                }
                if (P[t.first].mother != -1)
                {
                    B.insert(P[t.first].mother);
                    q.push(pair<int, int>(P[t.first].mother, t.second + 1));
                }
            }
            bool flag = false;
            for (auto t : A)
                if (B.count(t) != 0)
                    flag = true;
            if (flag)
                cout << "No" << endl;
            else    
                cout << "Yes" << endl;
        }
	}
	return 0;
}