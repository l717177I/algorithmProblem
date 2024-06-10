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

void debugnode(void)
{
	for (int i = 1; i <= n; i++) printf(" (%d,%d) ->", i, nodes[i]);
	printf("END\n");
}

int check_nodes(void)
{
	for (int i = 1; i <= n; i++)
	{
		if (!nodes[i]) return 0;
	}
	debugnode();
	return 1;
}

void dfs(int cur, int weight) // y, x 좌표를 모두 받아와야 되는가?
{
	if (cur == start && check_nodes())
	{
		printf("sol = %d\n", sol);
		if (sol > weight) sol = weight;
		return;
	}
	// 현재 방문했더 ㄴ노드를 그대로 방문하고 있음. 확인 필요
	for (int i = cur; i <= n; i++)
	{
		if (nodes[i]) continue;
		for (int next = 1; next <= n; next++)
		{
			if (i == next) continue; // 가지치기인데 뭐 0이라 밑에서도 처리되긴함
			if (!w[i][next] || visited[i][next]) continue;
			nodes[i] = next;
			visited[i][next] += w[i][next];
			dfs(next, visited[i][next]);
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
		dfs(i, 0);
		memset(visited, 0, sizeof(visited));
		memset(nodes, 0, sizeof(nodes));
	}
	debugnode();
	printf("%d\n", sol);
	return 0;
}
