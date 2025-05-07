#include <iostream>
#include <vector>

using namespace std;

void find(int virus, vector<vector<int>>& graph, int& total, vector<bool>& visited);

int main() {
	int num, count;
	cin >> num >> count;

	vector<vector<int>> graph(num + 1, vector<int>(num + 1));

	for (int i = 0; i < count; i++) {
		int x, y;
		cin >> x >> y;

		graph[x][y] = graph[y][x] = 1;
	}

	vector<bool> visited(num + 1, false);
	int total = 0;

	find(1, graph, total, visited);

	cout << total << "\n";

	return 0;
}

void find(int virus, vector<vector<int>>& graph, int& total, vector<bool>& visited) {
	visited[virus] = true;

	for (int i = 1; i < graph.size(); i++) {
		if (graph[virus][i] == 1 && !visited[i]) {
			total++;
			find(i, graph, total, visited);
		}
	}
}