//L1-025-������A+Bver2
//���ϵİ汾
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
    char a[10001],b[10001];
    int i,s1=0,s2=0,na,nb;
    scanf("%s",a);
    //��һ��%*c��˼�Ƕ�ȡ�����Ƹ�ֵ�������ո�
	scanf("%*c%[^\n]%*c",b);
    na=strlen(a);
    nb=strlen(b);
    for(i=0;i<na;i++)/*�ж�a*/
    {
        if(a[i]<'0'||a[i]>'9')/*����������֣��ñ��Ϊ1*/
        {
            s1=1;
            break;
        }
        //if(a[0]=='+')/*����Ƿ��ţ�����ø�*/
		//	s1--;
        if(atoi(a)<1||atoi(a)>1000)/*�ַ�ת����*/
			s1=1;/*���a��bΪС��0���ߴ���1000�����ñ��s1�ı�*/
    }
    for(i=0;i<nb;i++)/*�ж�b*/
    {
        if(b[i]<'0'||b[i]>'9')
        {
            s2=1;
            break;
        }
        /*if(b[0]=='+')
			s2--;*/
        if(atoi(b)<1||atoi(b)>1000)
			s2=1;
    }
    if(s1>=1&&s2>=1)
        printf("? + ? = ?\n");
    if(s1>=1&&s2==0)
        printf("? + %d = ?\n",atoi(b));
    if(s1==0&&s2>=1)
        printf("%d + ? = ?\n",atoi(a));
    if(s1==0&&s2==0)
    {
        printf("%d + %d = %d\n",atoi(a),atoi(b),atoi(a)+atoi(b));
    }
}
