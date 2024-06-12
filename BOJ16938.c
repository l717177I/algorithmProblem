#include <stdio.h>
int n, l, r, x;
int difficult[20];
void inputData(void)
{
	scanf("%d %d %d %d", &n, &l, &r, &x);
	for (int i = 0; i < n; i++) scanf("%d", &difficult[i]);
}

int main(void)
{
	inputData();
	// 구현
	return 0;
}
