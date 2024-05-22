#if 1
// 백준 2146
#include <stdio.h>
#define MAXN 100
int n;
int maps[MAXN + 10][MAXN + 10];

typedef struct
{
	int y, x, depth;
} Q;
Q que[MAXN * MAXN * 10];
int wp, rp;
Q pop(void) { return que[rp++]; }
int empty(void) { return (rp == wp); }
void push(int y, int x, int d) { que[wp].y = y; que[wp].x; que[wp++].depth = d; }

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

void bfs(void)
{
	;
}

void solution(void)
{
	wp = rp = 0;
	bfs();
}

int main(void)
{
	inputData();

	return 0;
}

#endif
