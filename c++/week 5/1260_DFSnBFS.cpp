#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited);
void bfs(int start, vector<vector<int>>& graph, vector<bool>& visited);

int main() {
	int N, M, V; // N: 정점 M: 간선 V: 시작 정점
	cin >> N >> M >> V;

	vector<vector<int>> graph(N + 1);
	while (M--) {
		int st, en;
		cin >> st >> en;

		graph[st].push_back(en);
		graph[en].push_back(st);
	}

	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	vector<bool> visited(N + 1, false);
	dfs(V, graph, visited);
	cout << "\n";
	vector<bool> visited2(N + 1, false);
	bfs(V, graph, visited2);
	return 0;
}

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
	visited[node] = true;
	cout << node << " ";
	for (int next : graph[node]) {
		if (!visited[next]) {
			dfs(next, graph, visited);
		}
	}
}

void bfs(int start, vector<vector<int>>& graph, vector<bool>& visited) {
	queue<int> Q;
	Q.push(start);
	visited[start] = true;

	while (!Q.empty()) {
		int node = Q.front();
		Q.pop();
		cout << node << " ";

		for (int next : graph[node]) {
			if (!visited[next]) {
				Q.push(next);
				visited[next] = true;
			}
		}
	}
}