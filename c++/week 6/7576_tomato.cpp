#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main() {
	int col, row; cin >> col >> row;
	vector<vector<int>> graph(row, vector<int>(col));
	vector<vector<bool>> visited(row, vector<bool>(col, false));
	queue<pair<int, int>> Q;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> graph[i][j];

			if (graph[i][j] == 1) {
				Q.push({ i, j });
				visited[i][j] = true;
			}
			else if (graph[i][j] == -1) visited[i][j] = true;
		}
	}
	int day = 0;
	while (!Q.empty()) {
		int size = Q.size();
		for (int i = 0; i < size; i++) {
			pair<int, int> front = Q.front(); Q.pop();

			for (int i = 0; i < 4; i++) {
				int x = front.second + dx[i]; int y = front.first + dy[i];
				if (y >= 0 && y < row && x >= 0 && x < col && !visited[y][x] && graph[y][x] != -1) {
					Q.push({ y, x }); visited[y][x] = true;
				}
			}
		}

		day++;
	}

	int result = --day;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (visited[i][j] == false) result = -1;
		}
	}
	cout << result << "\n";
	

	return 0;
}