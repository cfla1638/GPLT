//L2-026 Ð¡×Ö±²
#include <bits/stdc++.h>
using namespace std;

typedef struct 
{
    int degree = 0;
    int father;
    vector<int> sons;
}Peo;
int Max = -1;
Peo P[100005];
void DFS(int n)
{
    if (P[n].degree > Max)
        Max = P[n].degree;
    for (auto i : P[n].sons)
    {
        P[i].degree = P[n].degree + 1;
        DFS(i);
    }
}
int main(void)
{
    int N, bg;
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> P[i].father;
    for (int i = 1; i <= N; i++)
    {
        if (P[i].father != -1)
            P[P[i].father].sons.push_back(i);
        else
            bg = i;
    }
    P[bg].degree = 1;
    DFS(bg);
    vector<int> out;
    for (int i = 1; i <= N; i++)
        if (P[i].degree == Max)
            out.push_back(i);
    sort(out.begin(), out.end());
    cout << Max << '\n';
    for (vector<int>::size_type i = 0; i < out.size(); i++)
        if (i + 1 != out.size())
            cout << out[i] << " ";
        else
            cout << out[i];
    return 0;
}