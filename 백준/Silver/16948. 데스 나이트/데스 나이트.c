#include <stdio.h>
#define MAXN 200

int n, r1, c1, r2, c2;
int visited[MAXN + 5][MAXN + 5];
typedef struct
{
	int r, c, cnt;
}QUEUE;
QUEUE q[MAXN * MAXN];
int wp, rp;
void push(int r, int c, int cnt) { q[wp].r = r; q[wp].c = c; q[wp++].cnt = cnt; }
QUEUE pop(void) { return q[rp++]; }
int empty(void) { return wp == rp; }
void inputData(void)
{
	scanf("%d ", &n);
	scanf("%d %d %d %d ", &r1, &c1, &r2, &c2);
}

int Solution(void)
{
	int dr[] = { -2,-2,0,0,2,2 };
	int dc[] = { -1,1,-2,2,-1,1 };
	wp = rp = 0;
	push(r1, c1, 0);
	visited[r1][c1] = 1;
	while (!empty())
	{
		QUEUE cur = pop();
		if (cur.r == r2 && cur.c == c2) return cur.cnt;
		for (int i = 0; i < 6; i++)
		{
			int nr = cur.r + dr[i];
			int nc = cur.c + dc[i];
			if (nr >= n || nr < 0 || nc >= n || nc < 0) continue;
			if (visited[nr][nc]) continue;
			push(nr, nc, cur.cnt + 1);
			visited[nr][nc] = 1;
		}
	}
	return -1;
}

int main(void)
{
	int sol;
	inputData();
	sol = Solution();
	printf("%d\n", sol);
	return 0;
}