#include <bits/stdc++.h>
#include <queue>
#include <iostream>
using namespace std;

int board[1001][1001];
bool visited[1001];
int n, m, v;
queue<int> q;


void dfs(int idx) {
	cout << idx << " ";

	for (int i = 1; i <= n; i++) {
		if (board[idx][i] && !visited[i]) {
			visited[i] = true;
			dfs(i);
		}
	}
}


void bfs(int idx) {
	// visited[idx] = true;
	q.push(idx);

	while (!q.empty()) {
		idx = q.front();
		q.pop();
		cout << idx << " ";
		for (int i = 1; i <= n; i++) {
			if (board[idx][i] && !visited[i]) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		board[x][y] = 1;
		board[y][x] = 1;
	}

	
	visited[v] = true;
	dfs(v);
	cout << '\n';
	memset(visited, false, sizeof(visited));
	visited[v] = true;
	bfs(v);
	return 0;
}