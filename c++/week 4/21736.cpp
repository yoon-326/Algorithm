#include <iostream>
#include <vector>

using namespace std;

void dfs(int x, int y, vector<vector<char>>& campus);

bool visited[601][601];
int friends = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int row, column;
	cin >> row >> column;

	vector<vector<char>> campus(row, vector<char>(column));
	int x, y;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			char val;
			cin >> val;

			if (val == 'P' || val == 'X') campus[i][j] = val;
			else if (val == 'I') {
				x = i;
				y = j;
			}
		}
	}

	dfs(x, y, campus);

	if (friends == 0) cout << "TT" << "\n";
	else cout << friends << "\n";

	return 0;
}

void dfs(int x, int y, vector<vector<char>>& campus) {
	visited[x][y] = true;

	if (campus[x][y] == 'P') friends++;
	if (campus[x][y] == 'X') return;

	if (x + 1 < campus.size() && !visited[x + 1][y]) dfs(x + 1, y, campus);
	if (x - 1 >= 0 && !visited[x - 1][y]) dfs(x - 1, y, campus);
	if (y + 1 < campus[x].size() && !visited[x][y+1]) dfs(x, y + 1, campus);
	if (y - 1 >= 0 && !visited[x][y-1]) dfs(x, y - 1, campus);
}