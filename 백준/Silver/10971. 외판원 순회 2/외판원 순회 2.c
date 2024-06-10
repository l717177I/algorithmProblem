#include <stdio.h>
#include <string.h>
#define MAX 10
#define INF 1e9
int n;
int w[MAX + 2][MAX + 2];
int start;

int visited[MAX + 2];
int nodes[MAX + 2];
int sol = INF;

void inputData(void)
{
	scanf("%d ", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++) scanf("%d", &w[i][j]);
	}
}

void dfs(int cnt, int cur, int weight)
{
	if (cnt == n && w[cur][start])
	{
		if (sol > weight + w[cur][start]) sol = weight + w[cur][start];
		return;
	}

	for (int next = 1; next <= n; next++)
	{
		if (visited[next] || !w[cur][next]) continue;
		visited[next] = 1;
		dfs(cnt + 1, next, weight + w[cur][next]);
		visited[next] = 0;
	}
}

int main(void)
{
	inputData();
	for (int i = 1; i <= n; i++)
	{
		start = i;
		memset(visited, 0, sizeof(visited));
		visited[start] = 1;
		dfs(1, i, 0);
	}
	printf("%d\n", sol);
	return 0;
}