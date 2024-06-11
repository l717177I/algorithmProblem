#include <stdio.h>
#define MAX 50
// 연구소는 빈칸0, 벽1, 바이러스2    ㅂ
// 활성이가 비활성 있는 칸으로 가면 비활성이 활성으로 변함
int n, m;
int lab[MAX + 2][MAX + 2];
int visited[MAX + 2][MAX + 2];
int select[10 + 2]; // 바이러스는 10개 이하
int empty = 0;
int ans = 1e9;
int wp, rp, vp;
typedef struct
{
	int y, x;
}QUEUE;
QUEUE virus[10 + 2];
QUEUE que[MAX * MAX + 2];
QUEUE pop(void) { return que[rp++]; }
void push(int y, int x) { que[wp].y = y; que[wp++].x = x; }

void inputData(void)
{
	vp = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &lab[i][j]);
			if (lab[i][j] == 0) empty++;
			else if (lab[i][j] == 2)
			{
				virus[vp].y = i;
				virus[vp++].x = j;
			}
		}
	}
}

void spread_bfs(void) // 병균 퍼뜨리기
{
	int infect = 0;
	int total = 0;
	int dy[] = { 1,-1,0,0 };
	int dx[] = { 0,0,1,-1 };
	while (wp != rp)
	{
		QUEUE cur = pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
			if (lab[ny][nx] != 1 && visited[ny][nx] == -1)
			{
				visited[ny][nx] = visited[cur.y][cur.x] + 1;
				if (!lab[ny][nx])
				{
					infect++;
					total = visited[ny][nx];
				}
				push(ny, nx);
			}
		}
	}
	if (infect == empty && ans > total) ans = total;
}
void select_dfs(int cnt, int start)	// 바이러스 선택 (조합)
{
	if (cnt == m)
	{
		wp = rp = 0;	// que clear
		memset(visited, -1, sizeof(visited));
		for (int i = 0; i < vp; i++)
		{
			if (select[i])
			{
				int vy = virus[i].y;
				int vx = virus[i].x;
				push(vy, vx);
				visited[vy][vx] = 0;
			}
		}
		spread_bfs();
		return;
	}

	for (int i = start; i < vp; i++)
	{
		if (select[i]) continue;
		select[i] = 1;
		select_dfs(cnt + 1, i + 1);
		select[i] = 0;
	}
}

void solution(void)
{
	select_dfs(0, 0);
	if (ans == 1e9) printf("-1\n");
	else printf("%d\n", ans);
}

int main(void)
{
	inputData();
	solution();
	return 0;
}