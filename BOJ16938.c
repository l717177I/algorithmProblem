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
int select[15 + 5];
int visited[15 + 5];
int sol = 0;

int compare(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

void inputData(void)
{
	scanf("%d %d %d %d", &n, &l, &r, &x);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
}
// 1) 선택한 문제들이 적절한지 판단하는 함수. 이건 매번 Return 할 때 마다 확인
int isTrue(int cnt)
{
	int flag = 1;
	int sum = 0;
	for (int i = 0; i < cnt; i++) sum += select[i];
	if (sum < l || sum > r) flag = 0;
	return flag;
}
// 2) 문제를 고르는 경우의 수. 사용했던걸 다시 재사용해도 된다면 순열로 구현하자
/*
 가지치기 생각하자 가지치기
*/
void dfs(int cnt)
{
	if (cnt > 1)
	{
		if (select[cnt-1] - select[0] < x && isTrue(cnt)) sol++;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (visited[i]) continue;
		visited[i] = 1;
		select[cnt] = a[i];
		visited[i] = 0;
	}
}
int main(void)
{
	inputData();
	// 구현
	qsort(a, n, sizeof(int), compare);
	dfs(0);
	return 0;
}
