#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 }; // ÁÂ, ¿ì, À§, ¾Æ·¡

void dfs(int start_x, int start_y, vector<vector<bool>>& W, vector<vector<bool>>& visited, int& count);

int main() {
	int N; cin >> N;

	vector<vector<bool>> W(N, vector<bool>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char character; cin >> character;
			int integer = character - '0';
			(integer == 1) ? W[i][j] = true : W[i][j] = false;
		}
	}

	vector<vector<bool>> visited(N, vector<bool>(N));

	int count = 0, sum = 0;
	vector<int> num;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (W[y][x] && !visited[y][x]) {
				dfs(x, y, W, visited, count);
				int sum1 = 0;
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < N; j++) {
						if (visited[i][j]) sum1++;
					}
				}
				num.push_back(sum1 - sum);
				sum = sum1;
				count++;
			}
		}
	}

	sort(num.begin(), num.end());

	cout << count << "\n";
	for (int i = 0; i < num.size(); i++) {
		cout << num[i] << "\n";
	}

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