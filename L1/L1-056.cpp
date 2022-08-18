//L1-056 ²ÂÊı×Ö
#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    char name[10];
    int number;
}People;


int main(void)
{
    int N, ave = 0;
    People peo[10001];
    int minPeo = -1, min = 101;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> peo[i].name;
        cin >> peo[i].number; 
        ave += peo[i].number;
    }
    ave /= N;
    ave /= 2;

    for (int i = 0; i < N; i++)
    {
        if (abs(peo[i].number - ave) < min)
        {
            min = abs(peo[i].number - ave);
            minPeo = i;
        }
    }

    cout << ave << " " << peo[minPeo].name;
    return 0;
}