///L2-019 ÇÄÇÄ¹Ø×¢
#include <bits/stdc++.h>
using namespace std;


int main(void)
{
    int N, M;
    string name;
    set<string> subscribe;
    map<string, int> like;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> name;
        subscribe.insert(name);
    }
    
    int num;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> name >> num;
        like.insert(pair<string, int>(name, num));
    }
    double sum = 0, avg = 0;
    for (auto i : like)
        sum += i.second;
    avg = sum / M;

    vector<string> output;
    for (auto i : like)
    {
        if (i.second > avg && subscribe.count(i.first) == 0)
        {
            output.push_back(i.first);
        }
    }
    if (output.empty())
        cout << "Bing Mei You" << endl;
    else
    {
        sort(output.begin(), output.end());
        for (auto i : output)
        cout << i << endl;
    }
    return 0;
}