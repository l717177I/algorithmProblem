#include <stdio.h>
#define MAX 1000
int n, m;
char maps[MAX + 1][MAX + 1];

typedef struct
{
	int y, x, c;
} QUEUE;
QUEUE q[MAX * MAX * 2];
int wp, rp;
void push(int y, int x, int c){ q[wp].y = y; q[wp].x = x; q[wp++].c = c; }
QUEUE pop(void) { return q[rp++]; }
int visited[2][MAX + 1][MAX + 1];

void inputData(void)
{
	scanf("%d %d ", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%s ", maps[i]);
	}
}

int bfs(int sy, int sx, int c)
{
	wp = rp = 0;
	visited[c][sy][sx] = 1;
	push(0, 0, 0);
	int dy[] = { 1,-1,0,0 };
	int dx[] = { 0,0,1,-1 };
	while (wp != rp)
	{
		QUEUE cur = pop();
		if (cur.y == n - 1 && cur.x == m - 1) return visited[cur.c][cur.y][cur.x];
		for (int i = 0; i < 4; i++)
		{
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];
			if (ny >= n || ny < 0 || nx >= m || nx < 0 || visited[cur.c][ny][nx]) continue;
			if (maps[ny][nx] == '1' && cur.c == 0 && !visited[cur.c + 1][ny][nx]) // 벽부수기 가능한 경우
			{
				visited[cur.c + 1][ny][nx] = visited[cur.c][cur.y][cur.x] + 1;
				push(ny, nx, cur.c + 1);
			}
			else if (maps[ny][nx] == '0' && !visited[cur.c][ny][nx]) // 0인 경우 그냥 통과
			{
				visited[cur.c][ny][nx] = visited[cur.c][cur.y][cur.x] + 1;
				push(ny, nx, cur.c);
			}
		}
	}
	return -1;
}

int main(void)
{
	inputData();
	int sol = bfs(0, 0, 0);
	printf("%d\n", sol);
	return 0;
}