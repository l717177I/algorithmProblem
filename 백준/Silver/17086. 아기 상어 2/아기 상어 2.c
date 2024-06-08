#include <stdio.h>
#include <string.h>
#define MAX 50

int n, m;
int box[MAX + 2][MAX + 2];
int dy[] = { 1, 1, 1, 0, -1, -1, -1, 0 };
int dx[] = { -1, 0, 1, 1, 1, 0, -1, -1 };

int wp, rp;
typedef struct
{
	int y, x, d;
}QUEUE;
QUEUE que[100000];
QUEUE pop(void) { return que[rp++]; }
void push(int y, int x, int d) { que[wp].y = y; que[wp].x = x; que[wp++].d = d; }

int sol = -1;
int visited[MAX + 2][MAX + 2];
void inputData(void)
{
	scanf("%d %d ", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) scanf("%d ", &box[i][j]);
	}
}

int bfs(int sy, int sx)
{
	wp = rp = 0;
	memset(visited, 0, sizeof(visited));
	push(sy, sx, 0);
	visited[sy][sx] = 1;
	while (rp != wp)
	{
		QUEUE cur = pop();
		if (box[cur.y][cur.x] == 1) return cur.d;
		for (int i = 0; i < 8; i++)
		{
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];
			if (ny >= n || ny < 0 || nx >= m || nx < 0 || visited[ny][nx]) continue;
			visited[ny][nx] = 1;
			push(ny, nx, cur.d + 1);
		}
	}
}

void solution(void)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (box[i][j] == 1) continue; // 상어 있으면 패쓰
			int tmp = bfs(i, j);
			if (tmp > sol) sol = tmp;
		}
	}
	printf("%d\n", sol);
}

int main(void)
{
	inputData();
	solution();
	return 0;
}