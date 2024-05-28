// https://eunsolsblog.tistory.com/entry/C-%EB%B0%B1%EC%A4%80-12851%EB%B2%88-%EC%88%A8%EB%B0%94%EA%BC%AD%EC%A7%88-2
#include <stdio.h>
#define MAX 100000

int dist[MAX + 2];
int cnt[MAX + 2];
// for Queue
int wp, rp;
int q[MAX * 2];
void push(int x) { q[wp++] = x; }
int pop(void) { return q[rp++]; }

void bfs(int start)
{
	wp = rp = 0;
	push(start);
	while (wp != rp)
	{
		int subin = pop();
		int dim[] = { subin + 1, subin - 1, subin * 2 };
		for (int nx = 0; nx < 3; nx++)
		{
			int next = dim[nx];
			if (next < 0 || next > MAX) continue;
			if (dist[next] != -1) // 이미 방문한 경우
			{
				// 최단거리가 같다면 카운팅 갱신
				if (dist[subin] + 1 == dist[next]) cnt[next] += cnt[subin];
			}
			else    // 최초 방문 시 최단 갱신
			{
				dist[next] = dist[subin] + 1;
				cnt[next] = cnt[subin];
				push(next);
			}
		}
	}
}

void solution(int n)
{
	for (int i = 0; i < MAX + 2; i++) dist[i] = -1;
	dist[n] = 0;
	cnt[n] = 1;
	bfs(n);
}

int main(void)
{
	int n, k;
	scanf("%d %d ", &n, &k);
	solution(n);
	printf("%d %d\n", dist[k], cnt[k]);
	return 0;
}