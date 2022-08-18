#include <stdio.h>
#include <math.h>
#define N 100

//�����ṹ��
typedef struct 
{
    long molecule;       //����
    long denominator;    //��ĸ
}Fraction;

long LCM(long m, long n);   //�������ֵ���С������
long GCD();
Fraction YF(Fraction f);    //Լ��

int main(void)
{
    Fraction f[N], sum;
    long AfterTfDenominator, factor, integer;
    int inputCount;
    int i, j, k;

    //�����û�����
    scanf("%d", &inputCount);
    for (i = 0; i < inputCount; i++)
    {
        scanf("%ld/%ld", &f[i].molecule, &f[i].denominator);
    }
    
    //������������С����ĸ
    AfterTfDenominator = f[0].denominator;
    for (i = 1; i < inputCount; i++)
    {
        AfterTfDenominator = LCM(AfterTfDenominator, f[i].denominator);
    }

    //�����з���ͨ��
    for (i = 0; i < inputCount; i++)
    {
        factor = AfterTfDenominator / f[i].denominator;
        f[i].denominator = AfterTfDenominator;
        f[i].molecule *= factor;
    }

    //���
    sum = f[0];
    for (i = 1; i < inputCount; i++)
    {
        sum.molecule += f[i].molecule;
    } 

    sum = YF(sum);
    //������
    integer = sum.molecule / sum.denominator;
    sum.molecule = sum.molecule - sum.denominator * integer;
    sum = YF(sum);

    if (sum.denominator < 0)
    {
        sum.denominator = (sum.denominator * -1);
        sum.molecule = (sum.molecule * -1);
    }
    if (integer == 0)
    {
        if (sum.molecule == 0)
        {
            printf("0");
            return 0;
        }
        printf("%ld/%ld", sum.molecule, sum.denominator);
    }
    else if(sum.molecule == 0L)
    {
        printf("%ld", integer);
    }
    else
    {
        printf("%ld %ld/%ld", integer, sum.molecule,sum.denominator);
    }

    return 0;
}

long LCM(long m, long n)
{
    long temp, i;
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

long GCD(long a, long b)
{
    if (b == 0) return a;
    return GCD(b, a % b);
}

Fraction YF(Fraction f)
{
    long maxFactor;
    maxFactor = GCD (f.denominator, f.molecule);
    f.molecule = f.molecule / maxFactor;
    f.denominator = f.denominator / maxFactor;
    return f;
}