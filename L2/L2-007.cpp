//L2-007 家庭房产
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 10000 //0000-9999
int par[MAX_N];     //父亲
int Rank[MAX_N];    //树的高度
void inti(int n){
    for (int i = 0; i < n; i++){
        par[i] = i;
        Rank[i] = 0;
    }
}
int find(int x){
    if (par[x] == x)return x;
    else return par[x] = find(par[x]);
}
void unite(int x, int y){
    x = find(x);
    y = find(y);
    if (x == y) return ;
    if (Rank[x] < Rank[y])
        par[x] = y;
    else{
        par[y] = x;
        if (Rank[x] == Rank[y])     //如果相等的话，更新新集合的高度
            Rank[x]++;
    }
}
bool same(int x, int y){
    return find(x) == find(y);
}
int cnt[MAX_N];
int S[MAX_N];
array<bool, MAX_N> exist;
struct family{
    vector<int> peo;
    double cnt;
    double S;
};
int main(void)
{
    int N;
    int num, dad, mom, k, child;
    inti(MAX_N);
    exist.fill(false);
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> num >> dad >> mom >> k;
        exist[num] = true;
        if (dad != -1) {unite(num, dad); exist[dad] = true;};
        if (mom != -1) {unite(num, mom); exist[mom] = true;}
        for (int j = 0; j < k; j++){
            cin >> child;
            exist[child] = true;
            unite(num, child);
        }
        cin >> cnt[num] >> S[num];
    }
    vector<family> F;
    for (int i = 0; i < MAX_N; i++){
        if (exist[i]){
            if (F.empty()){
                family t;
                t.peo.push_back(i);
                t.cnt = cnt[i];
                t.S = S[i];
                F.push_back(t);}
            else{
                bool flag = false;
                int pos;
                for (auto j = 0; j < F.size(); j++){
                    if (same(i, F[j].peo[0])){
                        flag = true;
                        pos = j;
                        break;}}
                if (flag){
                    F[pos].peo.push_back(i);
                    F[pos].cnt += cnt[i];
                    F[pos].S += S[i];}
                else{
                    family t;
                    t.peo.push_back(i);
                    t.cnt = cnt[i];
                    t.S = S[i];
                    F.push_back(t);
                    }
                }
            }
        }
    for (auto &e : F){
        e.S = e.S / e.peo.size();
        e.cnt = e.cnt / e.peo.size();
    }
    auto cmp = [](family a, family b){
        if (a.S != b.S) return a.S > b.S;
        else return a.peo[0] < b.peo[0];
    };
    sort(F.begin(), F.end(), cmp);
    cout << F.size() << endl;
    for (auto e : F){
        printf("%04d %d ", e.peo[0], e.peo.size());
        printf("%.3f %.3f\n", e.cnt, e.S);
    }
}