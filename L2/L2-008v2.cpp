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
    for (int i = 0; i < str.size(); i++){
        tmpAns = 0;
        for (int j = 0; i - j >= 0 && i + j + 1 < str.size(); j++){
            if (str[i - j] != str[i + 1 + j])
                break;
            tmpAns += 2;
        }
        maxAns = (maxAns > tmpAns ? maxAns : tmpAns);
    }
    
    tmpAns = 1;
    for (int i = 0; i < str.size(); i++){
        tmpAns = 1;
        for (int j = 1; i - j >= 0 && i + j < str.size(); j++){
            if(str[i-j]!=str[i+j])
                break;
            tmpAns +=2;
        }
            maxAns = (maxAns > tmpAns ? maxAns : tmpAns);
    }
    cout << maxAns << '\n';
    return 0;
}