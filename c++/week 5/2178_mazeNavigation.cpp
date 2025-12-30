#include <iostream>
#include <vector>

using namespace std;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 }; // ÁÂ, ¿ì, À§, ¾Æ·¡

void dfs(int start_x, int start_y, vector<vector<bool>>& W, vector<vector<bool>>& visited, int& count);

int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<bool>> W(N, vector<bool>(M));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char character; cin >> character;
			int integer = character - '0';
			(integer == 1) ? W[i][j] = true : W[i][j] = false;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << W[i][j] << " ";
		}
		cout << '\n';
	}

	vector<vector<bool>> visited(N, vector<bool>(M));

	int count = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (W[y][x] && !visited[y][x]) {
				dfs(x, y, W, visited, count);
				count++;
			}
		}
	}

	cout << count << "\n";

	return 0;
}

void dfs(int start_x, int start_y, vector<vector<bool>>& W, vector<vector<bool>>& visited, int& count) {
	visited[start_y][start_x] = true;

	for (int i = 0; i < 4; i++) {
		int next_x = start_x + dx[i];
		int next_y = start_y + dy[i];

		if (next_x >= 0 && next_x < W[0].size() && next_y >= 0 && next_y < W.size()) {
			if (!visited[next_y][next_x] && W[next_y][next_x]) {
				dfs(next_x, next_y, W, visited, count);
			}
		}
	}
}