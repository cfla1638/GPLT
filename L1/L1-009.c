//L1-009-N�������ver1
#include <stdio.h>
#define N 100

//�����ṹ��
typedef struct 
{
    long molecule;       //����
    long denominator;    //��ĸ
}Fraction;

int LCM(int m, int n);   //�������ֵ���С������
int GCD();
Fraction YF(Fraction f);    //Լ��

int main(void)
{
    Fraction f[N], sum;
    int AfterTfDenominator, factor, integer;
    int inputCount;
    int i, j, k;

    //�����û�����
    scanf("%d", &inputCount);
    for (i = 0; i < inputCount; i++)
    {
        scanf("%ld/%ld", &f[i].molecule, &f[i].denominator);
    }
    
    sum = f[0];
    //���
    for (i = 1; i < inputCount; i++)
    {
        //��������ĸ����С������
        AfterTfDenominator = LCM(sum.denominator, f[i].denominator);

        //�Ե�һ��������ͨ��
        factor = AfterTfDenominator / sum.denominator;
        sum.denominator = AfterTfDenominator;
        sum.molecule *= factor;

        //�Եڶ���������ͨ��
        factor = AfterTfDenominator / f[i].denominator;
        f[i].denominator = AfterTfDenominator;
        f[i].molecule *= factor;

        //�������
        sum.denominator = AfterTfDenominator;
        sum.molecule = sum.molecule + f[i].molecule;

        //Լ��
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
    if (m < n)  /*�Ƚϴ�С��ʹ��m�д洢������n�д洢С��*/
    {
        temp = m;
        m = n;
        n = temp;
    }
    for(i = m; i > 0; i++)  /*�Ӵ�����ʼѰ��������������Ȼ��*/
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