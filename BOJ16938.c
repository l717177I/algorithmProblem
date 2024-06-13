/*
 알고리즘 캠프에 사용할 문제 고르기
 문제 n개, i번째 문제의 난이도는 a[i]
 * 캠프에 사용할 문제는 최소 2문제 이상
 * 선택한 문제 a[i]들의 합을 sum이라 하면 l <= sum <= R
 * 절댓값 amax - amin >= x ==> qsort 사용하자
 * 캠프에 사용할 문제를 고르는 방법의 수 => 문제 선택 경우의 수다.
*/
#include <stdio.h>
#include <stdlib.h>
int n, l, r, x;
int a[15 + 5];
int sol = 0;

int compare(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

void inputData(void)
{
	scanf("%d %d %d %d", &n, &l, &r, &x);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
}
// 1) 선택한 문제들이 적절한지 확인
int isTrue(int sum, int max, int min)
{
	if ((sum >= l && sum <= r) && x <= max - min) return 1;
	return 0;
}
// 2) max-min 유효성 체크, 선택한 문제 합의 유효성 확인
void dfs(int start, int cnt, int sum, int max, int min)
{
	if (cnt > 1 && isTrue(sum, max, min)) sol++;
	if (sum > r) return;
	for (int i = start; i < n; i++)
	{
		int nmax = max > a[i] ? max : a[i];
		int nmin = min < a[i] ? min : a[i];
		choose[cnt] = a[i];
		dfs(i + 1, cnt + 1, sum + a[i], nmax, nmin);
	}
}

int main(void)
{
	inputData();
	qsort(a, n, sizeof(int), compare);
    	dfs(0, 0, 0, -1, 1e9);    // start, cnt, sum, max, min
	printf("%d\n", sol);
	return 0;
}
