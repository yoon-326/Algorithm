#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int distance = 0;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void bfs(int x, int y, vector<vector<int>>& maps, vector<vector<int>>& result);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int row, column;
	cin >> row >> column;

	vector<vector<int>> maps(row, vector<int>(column));
	int x, y;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			int val;
			cin >> val;

			maps[i][j] = val;
			if (val == 2) {
				x = i;
				y = j;
			}
		}
	}

	vector<vector<int>> result(row, vector<int>(column, -1));

	bfs(x, y, maps, result);

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (maps[i][j] == 0) cout << 0 << " ";
			else cout << result[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}

void bfs(int x, int y, vector<vector<int>>& maps, vector<vector<int>>& result) {
	queue<pair<int, int>> q;
	result[x][y] = 0;
	q.push({ x, y });
	while (!q.empty()) {
		int frontx = q.front().first;
		int fronty = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int cur_x = frontx + dx[i];
			int cur_y = fronty + dy[i];

			if (cur_x >= 0 && cur_x < maps.size() && cur_y >= 0 && cur_y < maps[x].size()) {
				if (result[cur_x][cur_y] == -1 && maps[cur_x][cur_y] == 1) {
					result[cur_x][cur_y] = result[frontx][fronty] + 1;
					q.push({ cur_x, cur_y });
				}
			}
		}
	}
}