#include <stdio.h>
#include <math.h>
#define MAX 10
int n, m;
int sry, srx, sby, sbx;
char board[MAX + 2][MAX + 2];

int visited[MAX + 2][MAX + 2][MAX + 2][MAX + 2];
int wp, rp;

typedef struct
{
	int ry, rx, by, bx, cnt;
}QUEUE;

QUEUE que[50000];
void markingAndPush(int ry, int rx, int by, int bx, int cnt)
{
	visited[ry][rx][by][bx] = 1;
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
	int dy[] = { 1,-1,0,0 };
	int dx[] = { 0,0,1,-1 };
	wp = rp = 0;
	markingAndPush(sry, srx, sby, sbx, 0);
	while (wp != rp)
	{
		QUEUE cur = pop();
		if (cur.cnt > 10) break;	// 카운트 10회 이상이면 종료
		if (board[cur.ry][cur.rx] == 'O') // 빨간구슬 구멍 도착
		{
			sol = 1;
			break;
		}
		for (int i = 0; i < 4; i++) // 굴리기
		{
			int nry = cur.ry;
			int nrx = cur.rx;
			int nby = cur.by;
			int nbx = cur.bx;
			while (!isWall(nry + dy[i], nrx + dx[i]) && board[nry][nrx] != 'O')
			{
				nry += dy[i];
				nrx += dx[i];
			}
			while (!isWall(nby + dy[i], nbx + dx[i]) && board[nby][nbx] != 'O')
			{
				nby += dy[i];
				nbx += dx[i];
			}
			if (board[nby][nbx] == 'O') continue;	// 구멍에 빠진다면
			if (nry == nby && nrx == nbx) // 빨강이와 파랑이는 똑같은 위치면 안됨
			{
				if (board[nry][nrx] != 'O')
				{
					int rd = abs(nry - cur.ry) + abs(nrx - cur.rx);
					int bd = abs(nby - cur.by) + abs(nbx - cur.bx);
					if (rd > bd) { nry -= dy[i]; nrx -= dx[i]; }
					else { nby -= dy[i]; nbx -= dx[i]; }
				}
			}
			if (!visited[nry][nrx][nby][nbx])
			{
				markingAndPush(nry, nrx, nby, nbx, cur.cnt + 1);
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