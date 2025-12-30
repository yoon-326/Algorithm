#include <iostream>
#include <vector>

using namespace std;

void DFS(int num, int index, vector<int>& arr, vector<int>& visited, int n, int m);

int main() {
	int N, M; cin >> N >> M;

	vector<int> arr(9);
	vector<int> visited(9);

	DFS(1, 0, arr, visited, N, M);

	return 0;
}

void DFS(int num, int index, vector<int>& arr, vector<int>& visited, int n, int m) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = num; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[index] = i;
			DFS(i + 1, index + 1, arr, visited, n, m);
			visited[i] = false;
		}
	}
}