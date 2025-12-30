#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N; cin >> N;
	vector<vector<bool>> graph(N, vector<bool>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int integer; cin >> integer;
			(integer == 1) ? graph[i][j] = true : graph[i][j] = false;
		}
	}

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (graph[i][k] == true && graph[k][j] == true)
					graph[i][j] = true;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}