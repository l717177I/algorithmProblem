#include <stdio.h>
#define MAX 125
#define INF 1e9
int n;
int cave[MAX + 2][MAX + 2];
int weights[MAX + 2][MAX + 2];
int wp, rp;
typedef struct
{
	int y, x, d;
} QUEUE;
QUEUE que[1000000];
QUEUE pop(void) { return que[rp++]; }
void push(int y, int x, int d) { que[wp].y = y; que[wp].x = x; que[wp++].d = d; }

void setVariable(void)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) scanf("%d", &cave[i][j]);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) weights[i][j] = INF;
	}
}

void bfs(int sy, int sx)
{
	wp = rp = 0;
	weights[sy][sx] = cave[sy][sx];
	push(sy, sx, weights[sy][sx]);
	while (wp != rp)
	{
		int dy[] = { 1,-1,0,0 };
		int dx[] = { 0,0,1,-1 };
		QUEUE cur = pop();
		if (weights[cur.y][cur.x] < cur.d) continue;
		for (int i = 0; i < 4; i++)
		{
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];
			int nd = cur.d + cave[ny][nx];
			if (ny >= n || ny < 0 || nx >= n || nx < 0) continue;
			if (weights[ny][nx] <= nd) continue;
			weights[ny][nx] = nd;
			push(ny, nx, nd);
		}
	}
}
int main(void)
{
	int cnt = 1;
	while (1)
	{
		scanf("%d", &n);
		if (!n) break;
		setVariable();
		bfs(0, 0);
		printf("Problem %d: %d\n", cnt, weights[n-1][n-1]);
		cnt++;
	}
	return 0;
}
