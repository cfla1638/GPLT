//L2-027 名人堂与代金券
#include <bits/stdc++.h>
using namespace std;

typedef struct Stu
{
    Stu() = default;
    Stu(string n, int s) : name(n), score(s){}
    string name;
    int score;
    int rank;
}Stu;


int main(void)
{
    int N, G, K;
    int value;
    int score; string name;
    vector<Stu> P;
    cin >> N >> G >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> name >> score;
        P.push_back(Stu(name, score));
    }
    auto cmp1 = [&](Stu a, Stu b){return a.score > b.score;};
    sort(P.begin(), P.end(), cmp1);
    //for (auto i : P)
    //    cout << i.score << " ";
    int pos1 = 0, pos2 = 0;     //必须初始化，不然对于全部不及格的情况会得到没有初始化的值
    for (vector<Stu>::size_type i = 0; P[i].score >= G && i < P.size(); i++)
        pos1 = i;
    for (vector<Stu>::size_type i = 0; P[i].score >= 60 && i < P.size(); i++)
        pos2 = i;
    if (pos1 != 0)
        pos1++; 
    if (pos2 != 0)
        pos2++;
    value = pos1 * 50 + (pos2 - pos1) * 20;

    P[0].rank = 1;
    for (vector<Stu>::size_type i = 1; i < P.size(); i++)
    {
        if (P[i].score == P[i - 1].score)
            P[i].rank = P[i-1].rank;
        else 
            P[i].rank = i + 1;
    }
    auto cmp2 = [&](Stu a, Stu b){
        if (a.score != b.score)
            return a.score > b.score;
        else
            return a.name < b.name;
    };
    sort(P.begin(), P.end(), cmp2);
    cout << value << '\n';
    for (vector<Stu>::size_type i = 0; P[i].rank <= K && i < P.size(); i++)
        cout << P[i].rank << " " << P[i].name << " " << P[i].score << endl;
    

    return 0;
}