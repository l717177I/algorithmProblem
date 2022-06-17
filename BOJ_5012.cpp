#include <iostream>
#include <vector>
#include <queue>
#define MAX 1000001
using namespace std;

int f, s, g, u, d;
bool visited[MAX];
int dist[MAX];
queue<int> q;
vector<int> dx;

void bfs(int x) {
	visited[x] = true;
	q.push(x);

	while (!q.empty()) {
		x = q.front();
		q.pop();
		
		for (int i = 0; i < 2; i++) {
			int nx = x + dx[i];
			
			if (0 < nx && nx <= f) {
				if (!visited[nx]) {
					visited[nx] = true;
					q.push(nx);
					dist[nx] = dist[x] + 1;
				}
			}
		}
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> f >> s >> g >> u >> d;
	dx.push_back(u);
	dx.push_back(-1 * d);

	bfs(s);

	if (visited[g]) {
		cout << dist[g];
	}
	else {
		cout << "use the stairs";
	}

	return 0;
}
