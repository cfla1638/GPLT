#include <bits/stdc++.h>
using namespace std;

bool check(string s)
{
	int length=s.size();
	if(length!=18) return false;//是不是18位 
	else
	{
		for(int i=0;i<18;i++)
		{
			if(s[i]<'0'||s[i]>'9')//是不是都是数字 
			{
				return false;
			}
		}
	}
	return true;
}

typedef struct Peo
{
    string name;
    int h, m;
    int stat;
    int sq;
    string id;
    bool operator==(const Peo &rhs)
    {
        return (this->name == rhs.name && this->id == rhs.id);
    }
}Peo;


int main(void)
{
    int D, P;
    vector<Peo> bad;
    map<string, int> done;
    cin >> D >> P;
    for (int i = 0; i < D; i++)
    {
        //new day
        for (auto &k : done)
        {
            if (k.second != 0)
            k.second--;
        }
        vector<Peo> td;
        int T, S, sq = 1;
        cin >> T >> S;
        for (int j = 0; j < T; j++)
        {
            int h, m, stat;
            string name, id;
            cin >> name >> id >> stat;
            scanf("%d:%d", &h, &m);
            getchar();
            if (check(id))
            {
                Peo P;
                P.name = name; P.id = id; P.sq = sq++; 
                P.h = h; P.m = m; P.stat = stat;
                td.push_back(P);
                if (P.stat == 1 && count(bad.begin(), bad.end(), P) == 0)
                    bad.push_back(P);
            } 
        }
        auto cmp = [](Peo a, Peo b){
                if (a.h != b.h) return a.h < b.h;
                else if (a.m != b.m) return a.m < b.m;
                else return a.sq < b.sq; 
            };
        sort(td.begin(), td.end(), cmp);
        int l = 0;
        for (int k = 0; k < S && l < td.size();)
        {
            if (done.find(td[l].id) != done.end() && done[td[l].id] != 0)
                l++;
            else
            {
                done[td[l].id] = P + 1;
                cout << td[l].name << " " << td[l].id << endl;
                k++;
                l++;
            }
        }
    }
    for (auto i : bad)
        cout << i.name << " " << i.id << endl;

    return 0;
}