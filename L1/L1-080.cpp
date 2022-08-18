//L1-080 乘法口诀数列
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int A[1000] = {0}, input, sz = 0, max, t, cursor = 2;

    for (int i = 0; i < 2; i++)
    {
            cin >> input;
        if (input >= 10)
        {
            A[sz++] = input / 10;
            A[sz++] = input % 10;
        }
        else
            A[sz++] = input;
    }
    cin >> max;
    while (sz < max)
    {
        t = A[cursor - 2] * A[cursor - 1];
        if (t >= 10)
        {
            A[sz++] = t / 10;
            A[sz++] = t % 10;
        }
        else
        {
            A[sz++] = t; 
        }
        cursor++;
    }
    for (int i = 0; i < max; i++)
    {
        if (i != max - 1)
            cout << A[i] << " ";
        else    
            cout << A[i];
    }

    return 0;
}
