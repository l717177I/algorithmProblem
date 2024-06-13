#include <stdio.h>
#include <stdlib.h>
#define MAX 100000
int n;
int sche[MAX + 10];
typedef struct
{
	int s, e;
}PLAN;
PLAN p[MAX + 10];

void inputData(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d %d", &p[i].s, &p[i].e);
}

int compare(const void* a, const void* b)
{
	PLAN* x = (PLAN*)a;
	PLAN* y = (PLAN*)b;
	if (x->e > y->e) return 1;
	else if (x->e < y->e) return -1;
	else
	{
		if (x->s > y->s) return 1;
		else if (x->s < y->s) return -1;
	}
	return 0;
}

int solution(void)
{
	int cnt = 1, end = p[0].e;
	for (int i = 1; i < n; i++)
	{
		if (p[i].s < end) continue;
		cnt++;
		end = p[i].e;
	}
	return cnt;
}

int main(void)
{
	inputData();
	qsort(p, n, sizeof(p[0]), compare);
	int ans = solution();
	printf("%d\n", ans);
	return 0;
}