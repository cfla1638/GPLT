//L2-008 最长对称子串
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    string str, scan;
    int maxAns = 0, tmpAns; 
    getline(cin, str);

    if (str.size() == 0){cout << 0; return 0;}
    if (str.size() == 1){cout << 1; return 0;}
    if (str.size() == 2){
        if (str[0] == str[1])   cout << 2 << '\n';
        else cout << 0 << '\n';
        return 0;
    }
    scan.push_back(str[0]);
    for (int i = 0; i + 1 < str.size(); i++){
        tmpAns = 0;
        for (int j = 0; i - j >= 0 && i + 1 + j <str.size(); j++)
            if (scan[i - j] == str[i + j + 1])
                tmpAns+=2;
        if (tmpAns > maxAns)
            maxAns = tmpAns;
        tmpAns = 1;
        for (int j = 1; i - j >= 0 && i + j < str.size(); j++)
            if (scan[i - j] == str[i + j])
                tmpAns+=2;
        if (tmpAns > maxAns)
            maxAns = tmpAns;
        scan.push_back(str[i + 1]);
    }
    cout << maxAns << '\n';
    return 0;
}