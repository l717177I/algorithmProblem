#include <stdio.h>
#include <string.h>
#define MAX 10
#define RED 0
#define BLUE 1
int n, m;
int sry, srx, sby, sbx;
char board[MAX + 2][MAX + 2];

int visited[MAX + 2][MAX + 2][MAX + 2][MAX + 2];
int wp, rp;

typedef struct {
	int ry, rx, by, bx, cnt;
} QUEUE;

QUEUE que[50000];

void push(int ry, int rx, int by, int bx, int cnt)  // queue에 푸시
{
	que[wp].ry = ry; que[wp].rx = rx;
	que[wp].by = by; que[wp].bx = bx;
	que[wp++].cnt = cnt;
}

QUEUE pop(void) { return que[rp++]; }   // queue popleft()

int isWall(int y, int x)
{
	if (board[y][x] == '#') return 1;
	return 0;
}

void checkVisited(int ry, int rx, int by, int bx, int cnt)
{
	visited[ry][rx][by][bx] = 1;
	push(ry, rx, by, bx, cnt);
}

void inputData(void)
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf(" %c", &board[i][j]);
			if (board[i][j] == 'R')
			{
				sry = i;
				srx = j;
			}
			else if (board[i][j] == 'B')
			{
				sby = i;
				sbx = j;
			}
		}
	}
}

int bfs(void)
{
	int sol = 0;
	int dy[] = { 1, -1, 0, 0 };
	int dx[] = { 0, 0, 1, -1 };
	wp = rp = 0;
	push(sry, srx, sby, sbx, 0);
	visited[sry][srx][sby][sbx] = 1;
	while (wp != rp)
	{
		QUEUE cur = pop();
		if (cur.cnt > 10) break; // 10번 이상이면 종료
		if (board[cur.ry][cur.rx] == 'O' && board[cur.by][cur.bx] != 'O')
		{
			sol = 1;
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int nry = cur.ry, nrx = cur.rx, nby = cur.by, nbx = cur.bx;

			while (!isWall(nry + dy[i], nrx + dx[i]) && board[nry][nrx] != 'O') { nry += dy[i]; nrx += dx[i]; }
			while (!isWall(nby + dy[i], nbx + dx[i]) && board[nby][nbx] != 'O') { nby += dy[i]; nbx += dx[i]; }

			if (board[nby][nbx] == 'O') continue; // 파란 구슬이 구멍에 빠지면 무시

			if (nry == nby && nrx == nbx) // 겹치는 경우 처리
			{
				if (board[nry][nrx] != 'O')
				{
					int red_dist = abs(nry - cur.ry) + abs(nrx - cur.rx);
					int blue_dist = abs(nby - cur.by) + abs(nbx - cur.bx);
					if (red_dist > blue_dist) { nry -= dy[i]; nrx -= dx[i]; }
					else { nby -= dy[i]; nbx -= dx[i]; }
				}
			}

			if (!visited[nry][nrx][nby][nbx])
			{
				checkVisited(nry, nrx, nby, nbx, cur.cnt + 1);
			}
		}
	}
	return sol;
}

int main(void)
{
	inputData();
	int ans = bfs();
	printf("%d\n", ans);
	return 0;
}
