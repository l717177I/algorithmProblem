#include <stdio.h>  // 과자 나눠주기

int arr[1000000];

int binary_search(int* arr, int m, int n)
{
	int left = 1, right = 1000000000;
	int mid, ans = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;

		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			cnt += arr[i] / mid;
		}
		if (cnt >= m)
		{
			ans = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return ans;
}

int main()
{
	int m, n;
	scanf("%d %d", &m, &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	printf("%d", binary_search(arr, m, n));

	return 0;
}