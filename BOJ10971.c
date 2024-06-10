#include <stdio.h>
#include <string.h>
#define MAX 10
#define INF 1e9
int n, start;
int w[MAX + 2][MAX + 2];

int visited[MAX + 2][MAX + 2];
int nodes[MAX + 2];
int cp[MAX + 2][MAX + 2];
int sol = INF;

void inputData(void)
{
	scanf("%d ", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &w[i][j]);
			cp[i][j] = w[i][j];
		}
	}
}

int check_nodes(void)
{
	for (int i = 1; i <= n; i++)
	{
		if (!nodes[i]) return 0;
	}
	for (int i = 1; i <= n; i++) printf("%d ", nodes[i]);
	printf("\n");
	return 1;
}


void dfs(int cnt, int cur, int weight) // y, x 좌표를 모두 받아와야 되는가?
{
	if (cur == start && check_nodes())
	{
		printf("sol = %d\n", sol);
		if (sol > weight) sol = weight;
		return;
	}

	for (int i = cur; i <= n; i++)
	{
		if (nodes[i]) continue;
		nodes[i] = 1;
		for (int next = 1; next <= n; next++)
		{
			if (i == next) continue; // 가지치기인데 뭐 0이라 밑에서도 처리되긴함
			if (!w[i][next] || visited[i][next]) continue;
			visited[i][next] += w[i][next];
			dfs(cnt + 1, next, visited[i][next]);
			visited[i][next] -= w[i][next];
		}
	}
}
void debuging(void)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf("%d ", visited[i][j]);
		}
		printf("\n");
	}
}

int main(void)
{
	inputData();
	for (int i = 1; i <= n; i++)
	{
		start = i;
		dfs(0, i, 0);
		memset(visited, 0, sizeof(visited));
		memset(nodes, 0, sizeof(nodes));
	}
	printf("%d\n", sol);
	return 0;
}
