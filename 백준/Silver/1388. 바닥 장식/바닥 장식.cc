#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> board(n, vector<char>(m)); //bd: BaDak
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		char x = 'x';
		for (int j = 0; j < m; j++) {
			if (board[i][j] == '-') {
				if (board[i][j] != x) cnt++;
			}
			x = board[i][j];
		}

	}
	
	for (int j = 0; j < m; j++) {
		char x = 'x';
		for (int i = 0; i < n; i++) {
			if (board[i][j] == '|') {
				if (board[i][j] != x) cnt++;
			}
			x = board[i][j];
		}

	}
	cout << cnt;
	return 0;
}