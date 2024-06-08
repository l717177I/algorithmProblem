#include <stdio.h>
#include <string.h>

#define MAX 1000

int n, m;
int graph[MAX + 1][MAX + 1];
int visited[MAX + 1];
int sol;

void inputData(void) {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {  // 그래프 초기화
        for (int j = 1; j <= n; j++) {
            graph[i][j] = -1;
        }
    }
    for (int i = 1; i < n; i++) {  // 간선 정보 입력
        int y, x, d;
        scanf("%d %d %d", &y, &x, &d);
        graph[y][x] = d;
        graph[x][y] = d;
    }
}

void dfs(int start, int end, int d) {
    if (start == end) {  // 시작과 끝이 같으면 더 탐색할 필요 없음
        sol = d;
        return;
    }
    visited[start] = 1;
    for (int i = 1; i <= n; i++) {
        if (graph[start][i] > 0 && !visited[i]) {
            dfs(i, end, d + graph[start][i]);
            if (sol != -1) return;  // 경로를 찾으면 더 이상 탐색하지 않음
        }
    }
}

int main(void) {
    inputData();
    for (int i = 0; i < m; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        memset(visited, 0, sizeof(visited));
        sol = -1;
        if (graph[start][end] != -1) {
            sol = graph[start][end];
        } else {
            dfs(start, end, 0);
        }
        printf("%d\n", sol);
    }
    return 0;
}
