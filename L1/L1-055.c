//L1-055-谁是赢家
#include <stdio.h>

typedef struct
{
    char name;
    int P1;
    int P2;
}Racer;

int main(void)
{
    Racer list[2];
    int i, input;
    list[0].name = 'a';
    list[1].name = 'b';
    list[0].P2 = list[1].P1 = 0;
    
    scanf("%d %d", &list[0].P1, &list[1].P1);
    for (i = 0; i < 3; i++)
    {
        scanf("%d", &input);
        if (input == 1)
            list[1].P2++;
        else
            list[0].P2++;
    }
    
    if(list[0].P2 == 3)
        printf("The winner is %c: %d + %d", list[0].name, list[0].P1, list[0].P2);
    else if (list[1].P2 == 3)
        printf("The winner is %c: %d + %d", list[1].name, list[1].P1, list[1].P2);
    else if(list[0].P1 > list[1].P1)
        printf("The winner is %c: %d + %d", list[0].name, list[0].P1, list[0].P2);
    else
        printf("The winner is %c: %d + %d", list[1].name, list[1].P1, list[1].P2);
    
    return 0;
}

/*  网上的版本（正确）
#include"stdio.h"
int main()
{
  int a,b,p1,p2;
  int x,y,z;
  scanf("%d%d",&a,&b);
  scanf("%d%d%d",&x,&y,&z);
  p2=x+y+z;
  if(p2==3)
  printf("The winner is b: %d + %d",b,p2);
  else if(p2==0)
  printf("The winner is a: %d + %d",a,3-p2);
  else if(a>b)
  printf("The winner is a: %d + %d",a,3-p2);
  else
  printf("The winner is b: %d + %d",b,p2);
  return 0;
}
*/