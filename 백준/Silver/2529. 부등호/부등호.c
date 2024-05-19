#include<stdio.h>
#include<string.h>

void swap(int a, int b);
void bf(int flag, int n);
int check();

char str[11], max[11], min[11], copy[11];

int main() {
	int k, i;
	scanf("%d", &k);
	for (i = 0; i <= k; i++) {
		if (i != k) {
			getchar();
			str[i] = getchar();
		}
		else str[i] = NULL;
		max[i] = '9' - k + i;
		min[i] = '0' + k - i;
	}
	max[i] = NULL;
	min[i] = NULL;
	strcpy(copy, max);
	bf(1, k+1);
	strcpy(copy, min);
	bf(0, k + 1);
	printf("%s\n%s", max, min);
    	return 0;
}

void swap(int a, int b) {
	char tmp;
	tmp = copy[a];
	copy[a] = copy[b];
	copy[b] = tmp;
}
void bf(int flag, int n) {
	if (n == 1) {
		if (check()) {
			if (flag) {
				if (strcmp(max, copy) < 0) {
					strcpy(max, copy);
				}
			}
			else {
				if (strcmp(min, copy) > 0) {
					strcpy(min, copy);
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		swap(i, n - 1);
		bf(flag, n - 1);
		swap(i, n - 1);
	}
}
int check() {
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == '<') {
			if (copy[i] >= copy[i + 1]) {
				return 0;
			}
		}
		else if(str[i] == '>'){
			if (copy[i] <= copy[i + 1]) {
				return 0;
			}
		}
	}
	return 1;
}
//출처: https://angangmoddi.tistory.com/42 [Language Note:티스토리]