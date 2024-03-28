#include <stdio.h>
#define MAX	250

int m, n;
int pic[MAX + 10][MAX + 10] = { 0 };
int visited[MAX + 10][MAX + 10];

void inputData(void)
{
	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++) scanf("%d", &pic[i][j]);
	}
}

// A 의 경우, 한 정점에서 시작해서 왼쪽 대각선이 끝났을 때, 꼭짓점으로 돌아가 오른쪽 대각선을 칠해야한다
void dfs(int y, int x)
{
	static int dy[] = { 0,0,-1,1,-1,-1,1,1 };
	static int dx[] = { 1,-1,0,0,-1,1,-1,1 };
	visited[y][x] = 1;
	for (int i = 0; i < 8; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= m || ny < 0 || nx >= n || nx < 0) continue;
		if (pic[ny][nx] == 1 && !visited[ny][nx]) dfs(ny, nx);
	}
}

int Solution(void)
{
	int cnt = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (pic[i][j] == 1 && !visited[i][j])
			{
				dfs(i, j);
				cnt += 1;
			}
		}
	}
	return cnt;
}

int main(void)
{
	int ans;
	inputData();
	ans = Solution();
	printf("%d\n", ans);
	return 0;
}