//L1-048 ¾ØÕóA³ËÒÔB
#include <stdio.h>

int getC(const int A[][100], const int B[][100], int m, int s1, int s2, int n, int x, int y);

int main(void)
{
    int A[100][100], B[100][100];
    int C[100][100] = {0};
    int i, j, m, s1, s2, n;
    
    scanf("%d %d", &m, &s1);
    for (i = 0; i < m; i++)
        for (j = 0; j < s1; j++)
            scanf("%d", &A[i][j]);

    scanf("%d %d", &s2, &n);
    for (i = 0; i < s2; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &B[i][j]);
    
    if (s1 != s2)
    {
        printf("Error: %d != %d", s1, s2);
        return 0;
    }
    printf("%d %d\n", m, n);
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            C[i][j] = getC(A, B, m, s1, s2, n, i, j);
        }
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d", C[i][j]);
            if (j != (n - 1))
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}

int getC(const int A[][100], const int B[][100], int m, int s1, int s2, int n, int x, int y)
{
    int i, j;
    int ans = 0;

    for (i = 0, j = 0; i < s1; i++, j++)
    {
            ans += A[x][i] * B[j][y];
    }
    return ans;
}