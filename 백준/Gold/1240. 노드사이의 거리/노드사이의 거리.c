#include <stdio.h>
#include <string.h>
#define MAX 1000
int n, m;
int graph[MAX + 2][MAX + 2];
int visited[MAX + 2];
int sol;

void inputData(void)
{
	scanf("%d %d ", &n, &m);
	for (int i = 1; i < n; i++)
	{
		int y, x, d;
		scanf("%d %d %d ", &y, &x, &d);
		graph[x][y] = d;
		graph[y][x] = d;
	}
}
void dfs(int start, int end, int d)
{
	visited[start] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (graph[start][i] > 0 && !visited[i])
		{
			if (i == end)
			{
				sol = d + graph[start][i];
				return;
			}
			else dfs(i, end, d + graph[start][i]);
		}
	}
}

int main(void)
{
	inputData();
	for (int i = 0; i < m; i++)
	{
		int start, end;
		scanf("%d %d ", &start, &end);
		memset(visited, 0, sizeof(visited));
		sol = 0;
        dfs(start, end, 0);
		printf("%d\n", sol);
	}
	return 0;
}