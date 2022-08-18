//L1-059 «√±ø÷”
#include <bits/stdc++.h>
using namespace std;

typedef struct 
{
    char up[100];
    char down[100];
}Poem;

int YaYun(Poem P);
Poem Change(Poem P);

int main(void)
{
    Poem poem[100];
    int N;
    int i = 0, j = 0;

    cin >> N;
    getchar();
    while(i < N)
    {
        while((poem[i].up[j] = getchar()) != ',')
            j++;
        j = 0;
        while((poem[i].down[j] = getchar()) != '.')
            j++;
        j = 0;
        i++;
        getchar();
    }

    //poem[0] = Change(poem[0]);
    /*// ‰≥ˆ ‰»Î
    for (i = 0; i < N; i++)
    {
        cout << poem[i].up;
        cout << poem[i].down;
    }*/

    for (i = 0; i < N; i++)
    {
        if(YaYun(poem[i]))
        {
            poem[i] = Change(poem[i]);
            cout << poem[i].up <<poem[i].down << endl;
        }
        else
            cout << "Skipped" << endl;
    }

    return 0;
}

int YaYun(Poem P)
{
    int tag = 1;
    if (strcmp(P.up + strlen(P.up) - 4, "ong,") != 0)
        tag = 0;
    if (strcmp(P.down + strlen(P.down) - 4, "ong.") != 0)
        tag = 0;
    return tag;
}

Poem Change(Poem P)
{
    int i;
    int spaceCount = 0;
    
    i = strlen(P.down);
    while (spaceCount < 3)
    {
        if (P.down[i] == ' ')
            spaceCount++;
        i--;
    }
    i += 2;
    strcpy(&P.down[i], "qiao ben zhong.");
    return P;
}