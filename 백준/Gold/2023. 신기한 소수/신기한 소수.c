#include <stdio.h>

int checknum(int num)
{
    if (num < 2) return 0;
    for(int i=2; i*i<=num; i++) { if (num%i == 0) return 0; }
    return 1;
}

void dfs(int x, int y)
{
    if (y == 0) printf("%d\n", x);
    for(int i=1; i<10; i+=2)
    {
        int tmp = x*10 + i;
        if(checknum(tmp)) dfs(tmp, y-1);
    }
}

void Solution(int n)
{
    int prime[4] = {2, 3, 5, 7};
    for(int i=0;i<4;i++) { dfs(prime[i], n-1); }
}

int main(void)
{
    int n;
    scanf("%d",&n);
    Solution(n);
    return 0;
}