#include <stdio.h>
#define WEIGHT 500
// 백트래킹 - 순열을 활용한다.
int n, k, cnt;
int kit[10];
int visited[10] = { 0 };

void inputData(void)
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) { scanf("%d", &kit[i]); }
}

// m일차,누적운동량
void dfs(int m, int sum)
{
	if (sum < WEIGHT) return;
	if (m == n)	// n일차가 되었을 때
	{
		cnt += 1;
		return;	// 500 이하가 되는 케이스는 카운팅 x
	}
	sum -= k;
	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			dfs(m + 1, sum + kit[i]);
			visited[i] = 0;
		}
	}
}

int main(void)
{
	inputData();
    cnt = 0;
    dfs(0, 500);
	printf("%d\n", cnt);
	return 0;
}