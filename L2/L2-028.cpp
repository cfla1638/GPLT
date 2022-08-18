//L2-028 秀恩爱分得快
//测试点三答案错误，没找到问题
#include <bits/stdc++.h>
using namespace std;

double p[1000][1000];
int sex[1000];

int main(void)
{
    int N, M, K;
    memset(p, 0, sizeof(p));
    cin >> N >> M;
    while (M--)
    {
        vector<int> ls;
        string t;
        cin >> K;
        for (int k = 0; k < K; k++)
        {
            cin >> t;
            if (t[0] == '-')
                sex[abs(stoi(t))] = -1;
            else
                sex[abs(stoi(t))] = 1;
            ls.push_back(abs(stoi(t)));
        }
        for (vector<int>::size_type i = 0; i < ls.size(); i++)
            for (vector<int>::size_type j = i + 1; j < ls.size(); j++)
                p[ls[i]][ls[j]] += (double)1 / (double)K;
    }

    int A, B;
    double nowmax = -1;
    cin >> A >> B;
    
    A = abs(A); B = abs(B);

    vector<int> Amax;
    for (int i = 0; i < N; i++)
    {
        if (p[A][i] + p[i][A] > nowmax && (sex[A] + sex[i] == 0))
        {
            Amax.clear();
            Amax.push_back(i);
            nowmax = p[A][i] + p[i][A];
        }
        else if (p[A][i] + p[i][A] == nowmax && (sex[A] + sex[i] == 0))
        {
            Amax.push_back(i);
        }
    }

    nowmax = -1;
    vector<int> Bmax;

    

    for (int i = 0; i < N; i++)
    {
        if (p[B][i] + p[i][B] > nowmax && (sex[B] + sex[i] == 0))
        {
            Bmax.clear();
            Bmax.push_back(i);
            nowmax = p[B][i] + p[i][B];
        }
        else if (p[B][i] + p[i][B] == nowmax && (sex[B] + sex[i] == 0))
        {
            Bmax.push_back(i);
        }
    }

    sort(Amax.begin(), Amax.end());
    sort(Bmax.begin(), Bmax.end());

    if (sex[abs(A)] == 0 && sex[abs(B)] == 0 && count(Amax.begin(), Amax.end(), B) != 0 && count(Bmax.begin(), Bmax.end(), A) != 0)
    {
        cout << A << " " << B << endl;
        return 0; 
    }
    if (count(Amax.begin(), Amax.end(), B) != 0 && count(Bmax.begin(), Bmax.end(), A) != 0)
    {
        string A1 = to_string(A);
        string B1 = to_string(B);
        if (sex[A] < 0) A1 = string("-") + A1;
        if (sex[B] < 0) B1 = string("-") + B1;
        cout << A1 << " " << B1 << endl;
    }
    else
    {
        for (auto i : Amax)
        {
            string A1 = to_string(A);
            if (sex[A] < 0)
                A1 = string("-") + A1;
            string I = to_string(i);
            if  (sex[i] < 0)
                I = string("-") + I;
            cout << A1 << " " << I << endl;
        }
        for (auto i : Bmax)
        {
            string B1 = to_string(B);
            if (sex[B] < 0)
                B1 = string("-") + B1;
            string I = to_string(i);
            if  (sex[i] < 0)
                I = string("-") + I;
            cout << B1 << " " << I << endl;
        }
    }
    return 0;
}