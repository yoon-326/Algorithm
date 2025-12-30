#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int BFS(int n, int k, vector<bool>& visited);


int main() {
	int n, k; cin >> n >> k;

	vector<bool> visited(100001, false);
	int time = BFS(n, k, visited);

	cout << time << '\n';

	return 0;
}

int BFS(int n, int k, vector<bool>& visited) {
	queue<pair<int, int>> Q;
	if (n == k) return 0;;
	Q.push({ n, 0 }); visited[n] = true;

	while (!Q.empty()) {
		pair<int, int> front = Q.front(); Q.pop();
		
		if (front.first + 1 <= 100000 && !visited[front.first + 1]) {
			Q.push({ front.first + 1, front.second + 1 }); visited[front.first + 1] = true;
		}
		if (front.first - 1 >= 0 && !visited[front.first - 1]) {
			Q.push({ front.first - 1, front.second + 1 }); visited[front.first - 1] = true;
		}
		if (front.first * 2 <= 100000 && !visited[front.first * 2]) {
			Q.push({ front.first * 2, front.second + 1 }); visited[front.first * 2] = true;
		}

		if (front.first == k) {
			return front.second;
		}
	}
}