#include <stdio.h>
#define MAXN 100
int n;
int maps[MAXN + 10][MAXN + 10];
int visited[MAXN + 10][MAXN + 10];

int dy[] = { 1, -1,0,0 };
int dx[] = { 0,0,1,-1 };
typedef struct
{
	int y, x;
} Q;
Q que[MAXN * MAXN * 10];
int wp, rp;
Q pop(void) { return que[rp++]; }
int empty(void) { return (rp == wp); }
void push(int y, int x) { que[wp].y = y; que[wp++].x = x; }

void clear_visited(void)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			visited[i][j] = 0;
		}
	}
}

void inputData(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d ", &maps[i][j]);
		}
	}
}

void prinfmaps(void) // 디버깅용	
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", maps[i][j]);
		}
		printf("\n");
	}
}
// 1. 섬 별로 구역 나누기
void floodfill_dfs(int num, int y, int x)
{
	visited[y][x] = 1;
	maps[y][x] = num;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= n || ny < 0 || nx >= n || nx < 0
			|| visited[ny][nx] || !maps[ny][nx]) continue;
		floodfill_dfs(num, ny, nx);
	}
}
// 2. 최단 거리
int bfs(int v)
{
	wp = rp = 0;
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (maps[i][j] != v) continue;
			visited[i][j] = 1;
			push(i, j);
		}
	}
	while (!empty())
	{
		int size = wp - rp;
		for (int k = 0; k < size; k++)
		{
			Q cur = pop();
			for (int i = 0; i < 4; i++)
			{
				int ny = cur.y + dy[i];
				int nx = cur.x + dx[i];
				if (ny >= n || ny < 0 || nx >= n || nx < 0 || visited[ny][nx]) continue;
				if (maps[ny][nx] && maps[ny][nx] != v) return result;
				else if (!maps[ny][nx] && !visited[ny][nx])
				{
					visited[ny][nx] = 1;
					push(ny, nx);
				}
			}
		}
		result++;
	}
	return MAXN * MAXN;	// 디버깅
}

int solution(void)
{
	int num = 1;
	int ans = MAXN * MAXN;
	// 1) 섬 별로 구역 나누기
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (maps[i][j] && !visited[i][j]) floodfill_dfs(num++, i, j);
		}
	}
	// 2) 각 섬의 모든 지점에서 bfs하기
	for (int i = 1; i < num; i++)
	{
		clear_visited();
		int tmp = bfs(i);
		if (tmp < ans) ans = tmp;
	}
	return ans;
}

int main(void)
{
	inputData();
	int sol = solution();
	// prinfmaps();
	printf("%d\n", sol);
	return 0;
}