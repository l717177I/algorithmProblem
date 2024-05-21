#include <stdio.h>
#define ABS(y) (y)<(0) ? ((-1)*(y)) : (y)
#define MAXN 20

int s[MAXN + 1][MAXN + 1];
int n;
int sol = 1e9;
int visited[MAXN + 1];

void inputData(void)
{
	scanf("%d ", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d ", &s[i][j]);
		}
	}
}

int cal_score(void)
{
	int start = 0, link = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (visited[i] && visited[j]) start += s[i][j];
			if (!visited[i] && !visited[j]) link += s[i][j];
		}
	}
	return ABS(start - link);
}

void dfs(int cnt, int idx)
{
    if (sol == 0) return;
	if (cnt >= 1 && cnt <= n / 2)
	{
		int diff = cal_score();
		if (sol > diff) sol = diff;
	}

	for (int i = idx; i <= n; i++)
	{
        if (visited[i]) continue;
		visited[i] = 1;
		dfs(cnt + 1, i + 1);
		visited[i] = 0;
	}
}

int main(void)
{
	inputData();
	dfs(0, 1);
	printf("%d\n", sol);
	return 0;
}
