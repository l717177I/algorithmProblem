#include <stdio.h>
#include <string.h>
#define MAXN 100

int n;
int maps[MAXN + 10][MAXN + 10];
int visited[MAXN + 10][MAXN + 10];

int dy[] = { 1, -1, 0, 0 };
int dx[] = { 0, 0, 1, -1 };

typedef struct {
    int y, x;
} Q;
Q que[MAXN * MAXN * 10];
int wp, rp;

Q pop(void) { return que[rp++]; }
int empty(void) { return (rp == wp); }
void push(int y, int x) { que[wp].y = y; que[wp++].x = x; }

void clear_visited(void) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = 0;
        }
    }
}

void inputData(void) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &maps[i][j]);
        }
    }
}

void print_maps(void) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", maps[i][j]);
        }
        printf("\n");
    }
}

// 섬 별로 구역 나누기
void floodfill_dfs(int num, int y, int x) {
    visited[y][x] = 1;
    maps[y][x] = num;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny >= n || ny < 0 || nx >= n || nx < 0 || visited[ny][nx] || !maps[ny][nx]) continue;
        floodfill_dfs(num, ny, nx);
    }
}

// 최단 거리 계산
int bfs(int v) {
    wp = rp = 0;
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (maps[i][j] == v) {
                visited[i][j] = 1;
                push(i, j);
            }
        }
    }

    while (!empty()) {
        int size = wp - rp;
        for (int i = 0; i < size; i++) {
            Q cur = pop();
            for (int d = 0; d < 4; d++) {
                int ny = cur.y + dy[d];
                int nx = cur.x + dx[d];
                if (ny >= n || ny < 0 || nx >= n || nx < 0 || visited[ny][nx]) continue;
                if (maps[ny][nx] && maps[ny][nx] != v) return result;
                if (!maps[ny][nx] && !visited[ny][nx]) {
                    visited[ny][nx] = 1;
                    push(ny, nx);
                }
            }
        }
        result++;
    }
    return MAXN * MAXN;  // 큰 값 반환하여 최소값 갱신에 문제 없도록 함
}

int solution(void) {
    int num = 1;
    int ans = MAXN * MAXN;

    // 섬 별로 구역 나누기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (maps[i][j] && !visited[i][j]) {
                floodfill_dfs(num++, i, j);
            }
        }
    }

    for (int i = 1; i < num; i++) {
        clear_visited();
        int tmp = bfs(i);
        if (tmp < ans) ans = tmp;
    }

    return ans;
}

int main(void) {
    inputData();
    int sol = solution();
    // print_maps();
    printf("%d\n", sol);
    return 0;
}
