#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int kevinBC(int start, vector<vector<int>>& friends);
int bfs(vector<vector<int>>& friends, int start, int goal);

int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<int>> friends(N);
	while (M--) {
		int x, y; cin >> x >> y;
		friends[x - 1].push_back(y - 1);
		friends[y - 1].push_back(x - 1);
	}

	int min = INT_MAX;
	int min_index;
	for (int i = 0; i < N; i++) {
		int val = kevinBC(i, friends);
		if (val < min) {
			min = val;
			min_index = i;
		}
	}

	cout << min_index + 1 << "\n";

	return 0;
}

int kevinBC(int start, vector<vector<int>>& friends) {
	int sum = 0;

	for (int i = 0; i < friends.size(); i++) {
		if (i != start) {
			vector<bool> visited(friends.size(), false);
			sum += bfs(friends, start, i);
		}
	}

	return sum;
}

int bfs(vector<vector<int>>& friends, int start, int goal) {
	vector <bool> visited(friends.size(), false);
	queue<int> Q;
	vector<int> distance(friends.size(), 0);

	Q.push(start);
	visited[start] = true;

	while (!Q.empty()) {
		int current = Q.front();
		Q.pop();

		for (int next : friends[current]) {
			if (!visited[next]) {
				visited[next] = true;
				Q.push(next);
				distance[next] = distance[current] + 1;

				if (next == goal) return distance[next];
			}
		}
	}
}