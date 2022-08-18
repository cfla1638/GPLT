//L1-006-连续因子
#include <cstdio>
#include <algorithm>
#define MAXIMUN 1000
#define true 1
#define false 0

using namespace std;

//给print函数传入所有因子（每个因子数列按从小到大顺序排好）
//print函数即完成打印最长序列
//不同的因子数列中间要以-1分隔
void print(int factor[], int elemCount);    

int main(void)
{
    long int input;

    scanf("%ld", &input);

    return 0;
}

void print(int factor[], int elemCount)
{
    int i, recordTag, length, maxLen;       //recordTag记录是否开始记录连续因子
    int recordString[MAXIMUN], *maxLenString;

    length = 0;
    maxLen = 0;
    recordTag = false;
    
    //扫描整个factor数组
    for (i = 1; i <= elemCount; i++)
    {
        //开始记录连续序列
        if(((factor[i - 1] + 1) == factor[i]) && !recordTag)
        {
            recordTag = true;
            recordString[length] = factor[i - 1];
            length++;
        }
        //记录连续序列
        else if(((factor[i - 1] + 1) == factor[i]) && recordTag)
        {
            recordString[length] = factor[i - 1];
            length++;
        }

        //结束记录连续序列
        if(((factor[i - 1] + 1) != factor[i]) && recordTag)
        {
            recordTag = false;
            recordString[length] = factor[i - 1];
            length++;

            //判断是否需要更新最大连续序列
            //!!!是否需要考虑最大连续数列出现多个的情况
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