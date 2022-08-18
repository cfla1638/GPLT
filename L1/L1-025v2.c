//L1-025-正整数A+Bver2
//网上的版本
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
    char a[10001],b[10001];
    int i,s1=0,s2=0,na,nb;
    scanf("%s",a);
    //第一个%*c意思是读取但抑制赋值（跳过空格）
	scanf("%*c%[^\n]%*c",b);
    na=strlen(a);
    nb=strlen(b);
    for(i=0;i<na;i++)/*判断a*/
    {
        if(a[i]<'0'||a[i]>'9')/*如果不是数字，置标记为1*/
        {
            s1=1;
            break;
        }
        //if(a[0]=='+')/*如果是符号，标记置负*/
		//	s1--;
        if(atoi(a)<1||atoi(a)>1000)/*字符转数字*/
			s1=1;/*如果a，b为小于0或者大于1000，则让标记s1改变*/
    }
    for(i=0;i<nb;i++)/*判断b*/
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
