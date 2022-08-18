//L1-079 ÌìÌÝÈüµÄÉÆÁ¼
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    long input[20000];

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> input[i];

    int max, min, minCount = 0, maxCount = 0;
    max = min = input[0];
    for (int i = 0; i < n; i++)
    {
        if (input[i] > max)
        {
            max = input[i];
            maxCount = 1;
            continue;
        }

        if (input[i] == max)
        {
            maxCount++;
            continue;
        }    
        
    }
    for (int i = 0; i < n; i++)
    {
        if (input[i] < min)
        {
            min = input[i];
            minCount = 1;
            continue;
        }

        if (input[i] == min)    
        {
            minCount++;
            continue;
        }
    }

    cout << min << " " << minCount << endl;
    cout << max << " " << maxCount << endl;

    return 0;
}