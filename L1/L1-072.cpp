//L1-072 ¹Î¹Î²ÊÆ±
//²âÊÔµã3¹ı²»ÁË
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int num[3][3], sum = 0;
    int row, col;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> num[i][j];
            sum += num[i][j];
        }
    }

    for (int i = 1; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (num[i][j] == 0)
                num[i][j] = 45 - sum;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        cin >> row >> col;
        cout << num[row - 1][col - 1] << endl;
    }


    int pattern;
    cin >> pattern;

    switch (pattern)
    {
        case 1:
            sum = num[0][0] + num[0][1] + num[0][2]; break;

        case 2:
            sum = num[1][0] + num[1][1] + num[1][2]; break;

        case 3:
            sum = num[2][0] + num[2][1] + num[2][2]; break;

        case 4:
            sum = num[0][0] + num[1][0] + num[2][0]; break;

        case 5:
            sum = num[0][1] + num[1][1] + num[2][1]; break;

        case 6:
            sum = num[0][2] + num[1][2] + num[2][2]; break;

        case 7:
            sum = num[0][0] + num[1][1] + num[2][2]; break;

        case 8:
            sum = num[0][2] + num[1][1] + num[2][0]; break;
    }

    switch(sum)
    {
        case 6: cout << 10000 <<endl; break;
        case 7: cout << 36 <<endl; break;
        case 8: cout << 720 <<endl; break;
        case 9: cout << 360 <<endl; break;
        case 10: cout << 80 <<endl; break;
        case 11: cout << 252 <<endl; break;
        case 12: cout << 108 <<endl; break;
        case 13: cout << 72 <<endl; break;
        case 14: cout << 54 <<endl; break;
        case 15: cout << 180 <<endl; break;
        case 16: cout << 72 <<endl; break;
        case 17: cout << 180 <<endl; break;
        case 18: cout << 119 <<endl; break;
        case 19: cout << 36 <<endl; break;
        case 20: cout << 306 <<endl; break;
        case 21: cout << 1080 <<endl; break;
        case 22: cout << 144 <<endl; break;
        case 23: cout << 1800 <<endl; break;
        case 24: cout << 3600 <<endl; break;
    }
    return 0;
}