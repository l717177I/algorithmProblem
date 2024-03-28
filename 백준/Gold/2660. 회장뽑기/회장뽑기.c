#include <stdio.h>
#define MAX 50
#define INF 10000000
int n, pt;
int st[MAX + 1], node[MAX + 1][MAX + 1];

void initialize(void)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) node[i][j] = 0;
			else node[i][j] = INF;
		}
	}
}

void inputData(void)
{
	scanf("%d ", &n);
	initialize();
	while (1)
	{
		int f1, f2;
		scanf("%d %d ", &f1, &f2);
		if (f1 < 0 || f2 < 0) break;
		node[f1][f2] = 1;
		node[f2][f1] = 1;
	}
}

void checkNode(void)
{
	int i, j, k;
	pt = 0;
	for (k = 1; k <= n; k++)
	{
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (node[i][j] == 1) continue;
				else if (node[i][j] > node[i][k] + node[k][j]) node[i][j] = node[i][k] + node[k][j];
			}
		}
	}
	for (i = 1; i <= n; i++)
	{
		int max = -1;
		for (j = 1; j <= n; j++) { if (max < node[i][j]) max = node[i][j]; }
		st[pt++] = max;
	}
}

void Solution(void)
{
	int i, min = INF, cnt = 0;
	checkNode();
	for (i = 0; i < pt; i++)
	{
		if (min > st[i])
		{
			min = st[i];
			cnt = 1;
		}
		else if (min == st[i]) cnt++;
	}
	printf("%d %d \n", min, cnt);
	for (i = 0; i < pt; i++) { if (st[i] == min) printf("%d ", i + 1); }
}

int main(void)
{
	inputData();
	Solution();
	return 0;
}