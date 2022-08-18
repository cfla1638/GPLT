//L1-009-N个数求和ver1
#include <stdio.h>
#define N 100

//分数结构体
typedef struct 
{
    long molecule;       //分子
    long denominator;    //分母
}Fraction;

int LCM(int m, int n);   //返回数字的最小公倍数
int GCD();
Fraction YF(Fraction f);    //约分

int main(void)
{
    Fraction f[N], sum;
    int AfterTfDenominator, factor, integer;
    int inputCount;
    int i, j, k;

    //接受用户输入
    scanf("%d", &inputCount);
    for (i = 0; i < inputCount; i++)
    {
        scanf("%ld/%ld", &f[i].molecule, &f[i].denominator);
    }
    
    sum = f[0];
    //相加
    for (i = 1; i < inputCount; i++)
    {
        //求两个分母的最小公倍数
        AfterTfDenominator = LCM(sum.denominator, f[i].denominator);

        //对第一个数进行通分
        factor = AfterTfDenominator / sum.denominator;
        sum.denominator = AfterTfDenominator;
        sum.molecule *= factor;

        //对第二个数进行通分
        factor = AfterTfDenominator / f[i].denominator;
        f[i].denominator = AfterTfDenominator;
        f[i].molecule *= factor;

        //两数相加
        sum.denominator = AfterTfDenominator;
        sum.molecule = sum.molecule + f[i].molecule;

        //约分
        sum =  YF(sum);
    }

    integer = sum.molecule / sum.denominator;
    sum.molecule = sum.molecule - sum.denominator * integer;
    sum = YF(sum);

    if (integer == 0)
    {
        printf("%d/%d", sum.molecule, sum.denominator);
    }
    else if(sum.molecule == 0L)
    {
        printf("%d", integer);
    }
    else
    {
        printf("%d %d/%d", integer, sum.molecule,sum.denominator);
    }

    return 0;
}

int LCM(int m, int n)
{
    int temp, i;
    if (m < n)  /*比较大小，使得m中存储大数，n中存储小数*/
    {
        temp = m;
        m = n;
        n = temp;
    }
    for(i = m; i > 0; i++)  /*从大数开始寻找满足条件的自然数*/
        if(i % m == 0 && i % n==0)
        {
            return i;
        }
}

int GCD(int a, int b)
{
    if (b == 0) return a;
    return GCD(b, a % b);
}

Fraction YF(Fraction f)
{
    int maxFactor;
    maxFactor = GCD (f.denominator, f.molecule);
    f.molecule = f.molecule / maxFactor;
    f.denominator = f.denominator / maxFactor;
    return f;
}