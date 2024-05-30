// 백준 17406 - 백트래킹 OR 브루트포스
// rcs 순열을 뽑아서 각각의 최솟값 비교.
// K 최대 6, n, m 최대 50, O(K!*N*M) 약 180만 정도 될것으로 예상
#if 1
// 관건은 회전연산을 어떻게 구현할것인지
#include <stdio.h>
#include <string.h>
#define MAXN 50
int n, m, k;
//int rcs[MAXK + 2][3];
typedef struct
{
	int r, c, s;
} RCS_ARR;
RCS_ARR rcs[6 + 2];
int arr[MAXN + 10][MAXN + 10];
int sol = 1e9;

int order[6 + 2];	// rcs순서
int visited[6 + 2];

void inputData(void)
{
	scanf("%d %d %d ", &n, &m, &k);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 1; i <= k; i++)
	{
		scanf("%d %d %d", &rcs[i].r, &rcs[i].c, &rcs[i].s);
	}
}

void rotate(int (*copy_arr)[MAXN+10], int r, int c, int s) // 회전회오리!
{
	for (int t=1; t <= s; t++)
	{
		int tmp = copy_arr[r - t][c + t];
		// 순서대로 왼쪽, 아래쪽, 오른쪽, 위쪽!
		for (int i = r - t + 1; i <= r + t; i++) copy_arr[i - 1][c - t] = copy_arr[i][c - t];
		for (int i = c - t + 1; i <= c + t; i++) copy_arr[r + t][i - 1] = copy_arr[r + t][i];
		for (int i = r + t - 1; i >= r - t; i--) copy_arr[i + 1][c + t] = copy_arr[i][c + t];
		for (int i = c + t - 1; i >= c - t; i--) copy_arr[r - t][i + 1] = copy_arr[r - t][i];
		copy_arr[r - t][c - t + 1] = tmp;
	}
}

void calc_minOfArr(void)	// 배열의 최솟값 리턴
{
	int copy_arr[MAXN + 10][MAXN + 10];
	int sum = 0;
	memcpy(copy_arr, arr, sizeof(arr));
	for (int i = 1; i <= k; i++)
	{
		int idx = order[i];
		rotate(copy_arr, rcs[idx].r, rcs[idx].c, rcs[idx].s);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			sum += copy_arr[i][j];
		}
		if (sum < sol) sol = sum;
		sum = 0;
	}
}

void solution(int cnt)	// dfs
{
	if (cnt == k)
	{
		calc_minOfArr();
		return;
	}

	for (int i = 1; i <= k; i++)
	{
		if (visited[i]) continue;
		order[cnt] = i;
		visited[i] = 1;
		dfs(cnt + 1);
		visited[i] = 0;
	}
}

int main(void)
{
	inputData();
	solution(0);
	printf("%d\n", sol);
	return 0;
}

#endif
