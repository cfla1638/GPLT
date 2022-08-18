//试错数据：2 2 1； 2 2 5
//L1-049 天梯赛座位分配
#include <bits/stdc++.h>
using namespace std;

int getFoot(int *arr, int n);

int main(void)
{
    int M[100] = {0}, N, maxTeamCount;
    int seatNumber[100][10][10];
    int seqNumber = 1;
    int surplus[100];   //每轮剩下高校的队伍数量

    maxTeamCount = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> M[i];
        surplus[i] = M[i];
        if (M[i] > maxTeamCount)
            maxTeamCount = M[i];
    }

    int foot_schoolCount = N;   //步长 等价于本轮剩下多少个学校
    int start = 1, temp = 1;    //起始点
    int lastElem = -1;          //记录最后一个操作的元素
    int newTag = 1;             //记录是否是每队的第一个高校
    int i = 0, j, k;
    int preSchoolCount = -1;
    for (int team = 0; team < maxTeamCount; team++) //控制队伍
    {   
        i = 0;
        newTag = 1;
        preSchoolCount = foot_schoolCount;
        foot_schoolCount = getFoot(surplus, 100);
        //if (foot_schoolCount == 1)  //对只剩下一个队伍进行特判
        //    foot_schoolCount = 2;
        while (i < N)
        {
            while (!surplus[i] && i < N)     //寻找下一个高校
                i++;
            if (newTag && lastElem == i)
            {
                start++;
                newTag = 0;
            }
            if (foot_schoolCount == 1 && preSchoolCount == 1)
                start--;
            for (j = 0; j < 10; j++)
            {
                if (j == 0)     //每队的第一个元素特判
                {
                    seatNumber[i][team][j] = start;
                    temp = start;
                    start++;
                }
                else
                {
                    if (foot_schoolCount == 1)
                        temp += 2;
                    else
                        temp += foot_schoolCount;
                    seatNumber[i][team][j] = temp;
                    lastElem = i;
                }
            }
            surplus[i]--;
            i++;
        }
        start = temp + 1;
        if (foot_schoolCount == 1)
            start = temp + 2;
    }

    for (i = 0; i < N; i++)
    {
        cout << "#" << i + 1 <<endl;
        for (j = 0; j < M[i]; j++)
        {
            for (k = 0; k < 10; k++)
            {
                cout << seatNumber[i][j][k];
                if (k != 9)
                    cout << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}

int getFoot(int *arr, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i])
            count++;
    }
    return count;
}