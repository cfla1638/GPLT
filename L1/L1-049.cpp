//�Դ����ݣ�2 2 1�� 2 2 5
//L1-049 ��������λ����
#include <bits/stdc++.h>
using namespace std;

int getFoot(int *arr, int n);

int main(void)
{
    int M[100] = {0}, N, maxTeamCount;
    int seatNumber[100][10][10];
    int seqNumber = 1;
    int surplus[100];   //ÿ��ʣ�¸�У�Ķ�������

    maxTeamCount = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> M[i];
        surplus[i] = M[i];
        if (M[i] > maxTeamCount)
            maxTeamCount = M[i];
    }

    int foot_schoolCount = N;   //���� �ȼ��ڱ���ʣ�¶��ٸ�ѧУ
    int start = 1, temp = 1;    //��ʼ��
    int lastElem = -1;          //��¼���һ��������Ԫ��
    int newTag = 1;             //��¼�Ƿ���ÿ�ӵĵ�һ����У
    int i = 0, j, k;
    int preSchoolCount = -1;
    for (int team = 0; team < maxTeamCount; team++) //���ƶ���
    {   
        i = 0;
        newTag = 1;
        preSchoolCount = foot_schoolCount;
        foot_schoolCount = getFoot(surplus, 100);
        //if (foot_schoolCount == 1)  //��ֻʣ��һ�������������
        //    foot_schoolCount = 2;
        while (i < N)
        {
            while (!surplus[i] && i < N)     //Ѱ����һ����У
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
                if (j == 0)     //ÿ�ӵĵ�һ��Ԫ������
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