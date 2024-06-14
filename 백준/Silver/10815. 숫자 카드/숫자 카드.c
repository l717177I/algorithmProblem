#include <stdio.h>
#include <stdlib.h>
#define MAX 500000
int n, m;
int cards[MAX + 2];
void inputData(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &cards[i]);
}
int compare(const void* a, const void* b) { return (*(int*)a) - (*(int*)b); }

int binary_search(int num)
{
	int mid, end = n - 1, start = 0;
	while (end >= start)
	{
		mid = (end + start) / 2;
		if (cards[mid] > num) end = mid - 1;
		else if (cards[mid] < num) start = mid + 1;
		else break;
	}
	if (cards[mid] == num) return 1;
	return 0;
}

void solution(void)
{
	qsort(cards, n, sizeof(cards[0]), compare);
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
        int tmp;
		scanf("%d", &tmp);
		printf("%d ", binary_search(tmp));
	}
}

int main(void)
{
	inputData();
	solution();
	printf("\n");
	return 0;
}