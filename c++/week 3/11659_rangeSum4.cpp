#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> index(N + 1);
	vector<int> DP(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> index[i];
		DP[i] = DP[i - 1] + index[i];
	}

	while (M--) {
		int i, j;
		cin >> i >> j;

		cout << DP[j] - DP[i - 1] << "\n";
	}

	return 0;
}