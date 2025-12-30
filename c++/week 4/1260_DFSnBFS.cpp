#include <iostream>
#include <vector>

using namespace std;

void make_graph(vector<vector<int>>& graph, int node, int edge);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int node, edge, start;
	cin >> node >> edge >> start;

	vector<vector<int>> graph(node + 1, vector<int>(node + 1));
	make_graph(graph, node, edge);

	DFS(graph, node, start);
	BFS(graph, node, start);

	return 0;
}

void make_graph(vector<vector<int>>& graph, int node, int edge) {
	for (int i = 0; i < edge; i++) {
		int to, from;
		cin >> to >> from;

		graph[to][from] = 1;
		graph[from][to] = 1;
	}
}

void DFS(vector<vector<int>>& graph, int node, int start) {
	for (int i = start; i <= node; i++) {

	}
}

void BFS(vector<vector<int>>& graph, int node, int start) {

}