//L1-006-��������
#include <cstdio>
#include <algorithm>
#define MAXIMUN 1000
#define true 1
#define false 0

using namespace std;

//��print���������������ӣ�ÿ���������а���С����˳���źã�
//print��������ɴ�ӡ�����
//��ͬ�����������м�Ҫ��-1�ָ�
void print(int factor[], int elemCount);    

int main(void)
{
    long int input;

    scanf("%ld", &input);

    return 0;
}

void print(int factor[], int elemCount)
{
    int i, recordTag, length, maxLen;       //recordTag��¼�Ƿ�ʼ��¼��������
    int recordString[MAXIMUN], *maxLenString;

    length = 0;
    maxLen = 0;
    recordTag = false;
    
    //ɨ������factor����
    for (i = 1; i <= elemCount; i++)
    {
        //��ʼ��¼��������
        if(((factor[i - 1] + 1) == factor[i]) && !recordTag)
        {
            recordTag = true;
            recordString[length] = factor[i - 1];
            length++;
        }
        //��¼��������
        else if(((factor[i - 1] + 1) == factor[i]) && recordTag)
        {
            recordString[length] = factor[i - 1];
            length++;
        }

        //������¼��������
        if(((factor[i - 1] + 1) != factor[i]) && recordTag)
        {
            recordTag = false;
            recordString[length] = factor[i - 1];
            length++;

            //�ж��Ƿ���Ҫ���������������
            //!!!�Ƿ���Ҫ��������������г��ֶ�������
            if (length > maxLen)  
            {
                maxLen = length;
                maxLenString = recordString;
                length = 0;
            }
        }

        
    }

    printf("%d\n", maxLen);
    for (i = 0; i < maxLen; i++)
    {
        printf("%d", maxLenString[i]);
        if(i != maxLen - 1)
        {
            printf("*");
        }
    }
}