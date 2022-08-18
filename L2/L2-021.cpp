//L2-021 µãÔŞ¿ñÄ§
#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    string name;
    int tag;
    int sum;
    double rate;
}Peo;


int main(void)
{
    int N, K, tag;
    set<int> tagSet;
    vector<Peo> P;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        tagSet.clear();
        Peo t;
        cin >> t.name;
        cin >> K;
        for (int i = 0; i < K; i++)
        {
            cin >> tag;
            tagSet.insert(tag);
        }
        t.tag = tagSet.size();
        t.sum = K;
        t.rate = (double)t.sum / t.tag;
        P.push_back(t);
    }
    auto cmp = [](Peo a, Peo b){
        if (a.tag != b.tag) return a.tag > b.tag;
        else return a.rate < b.rate;
    };
    sort(P.begin(), P.end(), cmp);
    if (P.size() >= 3)
        for (int i = 0; i < 3; i++)
            if (i + 1 != 3)
                cout << P[i].name << " ";
            else
                cout << P[i].name << endl;
    else
    {
        int l = 3 - P.size();
        for (auto i : P)
            cout << i.name << " ";
        if (l == 3) cout << "- - -" <<endl;
        if (l == 2) cout << "- -" << endl;
        if (l == 1) cout << "-" << endl;
    }

    return 0;
}