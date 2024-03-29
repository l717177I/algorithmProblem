#define MAX 100
int m, n, k;
int x0, y0, x1, y2;
// int map[MAX][4] = { 0, };
int area[MAX*MAX] = { 0, };
int space[MAX][MAX] = { 0, };
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int num, width = 0;

void area_sort() {
	int tmp;
	for (int i = 0; i < num; i++) {
		for (int j = i+1; j < num; j++) {
			if (area[i] > area[j]) {
				tmp = area[i];
				area[i] = area[j];
				area[j] = tmp;
			}
		}
	}
}

void drawing(int lx, int ly, int rx, int ry) {
	for (int i = lx; i < rx; i++) {
		for (int j = ly; j < ry; j++) {
			space[i][j] += 1;
		}
	}
}

int dfs(int y, int x) {
	space[y][x] += 1;
	width += 1;
	area[num - 1] += 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if ((0 <= nx) && (nx < m) && (0 <= ny) && (ny < n) && space[ny][nx] == 0) {
			dfs(ny, nx);
			
		}
	}
}

int main(void) {
	int i, j;
	scanf("%d %d %d", &m, &n, &k);

	for (i = 0; i < k; i++) {
		scanf("%d %d %d %d", &x0, &y0, &x1, &y2);
		drawing(x0, y0, x1, y2);
	}

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (space[j][i] == 0) {
				//printf(i);
				num++;
				dfs(j, i);
			}
		}
	}

	area_sort();
	printf("%d\n", num);
	for (i = 0; i < num; i++)
		printf("%d ", area[i]);

	return 0;
}
