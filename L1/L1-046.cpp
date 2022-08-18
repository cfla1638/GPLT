#include <bits/stdc++.h>
using namespace std;
//使用atoi的话会溢出

int main(void)
{
    char GG[1000] = {0};
    char x[1000] = {0};
    int s, wid;
    cin >> x;
    for (int i = 0; i < strlen(x); i++)
    {
        GG[i] = '1';
    }
    wid = strlen(x);
    while(atoi(GG) % atoi(x))
    {
        GG[wid] = '1';
        wid++;
    }
    s = atoi(GG) / atoi(x);
    cout << s << " "<< wid;
    return 0;
}