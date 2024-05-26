#include <stdio.h>
#include <stdlib.h>
#define MAX 500000

int n, m;
int decks[MAX + 10];
int cards[MAX + 10];

int compare(const void* a, const void* b);

void inputData(void)
{
	scanf("%d ", &n);
	for (int i = 0; i < n; i++) scanf("%d ", &decks[i]);
	scanf("%d ", &m);
	for (int i = 0; i < m; i++) scanf("%d ", &cards[i]);
}

int lower_bound(int* card_arr, int val)
{
	int start = 0;
	int end = n;
	while (start < end)
	{
		int mid = (start + end) / 2;
		if (val <= card_arr[mid]) end = mid;
		else start = mid + 1;
	}
	return end;
}

int upper_bound(int* card_arr, int val)
{
	int start = 0;
	int end = n;
	while (start < end)
	{
		int mid = (start + end) / 2;
		if (card_arr[mid] > val) end = mid;
		else start = mid + 1;
	}
	if (decks[end] == val) return end + 1;
	return end;
}

void solution(void)
{
	qsort(decks, n, sizeof(int), compare);
	for (int i = 0; i < m; i++)
	{
		int lower = lower_bound(decks, cards[i]);
		int upper = upper_bound(decks, cards[i]);
		printf("%d ", upper - lower);
	}
}

int main(void)
{
	inputData();
	solution();
	return 0;
}

int compare(const void* a, const void* b)
{
	if (*(int*)a < *(int*)b) return -1;
	if (*(int*)a > *(int*)b) return 1;
	return 0;
}