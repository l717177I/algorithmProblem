#include <stdio.h>
#include <stdlib.h>
#define MAX 100000
int a[MAX + 10];
int li[MAX + 10];
int n, m;
int compare(const void* a, const void* b);

void inputData(void)
{
	scanf("%d ", &n);
	for (int i = 0; i < n; i++) scanf("%d ", &a[i]);
	scanf("%d ", &m);
	for (int i = 0; i < m; i++) scanf("%d ", &li[i]);
}

int solution(int x)
{
	int low = 0, high = n - 1;
	int sol = 0;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (x == a[mid])
		{
			sol = 1;
			break;
		}
		else if (x > a[mid]) low = mid + 1;
		else high = mid - 1;
	}
	return sol;
}

int main(void)
{
	inputData();
	qsort(a, n, sizeof(int), compare);	//	오름차순 정렬
	for (int i = 0; i < m; i++)
	{
		int ans = solution(li[i]);
		printf("%d\n", ans);
	}
	return 0;
}

int compare(const void* a, const void* b)
{
	if (*(int*)a < *(int*)b) return -1;
	else if (*(int*)a > *(int*)b) return 1;
	return 0;
}