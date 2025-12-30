#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binary_search(int low, int high, vector<int>& trees, int M);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;   // N: 나무의 수 M: 가져갈 길이
	cin >> N >> M;

	vector<int> trees(N);
	for (int i = 0; i < N; i++) {
		cin >> trees[i];
	}
	sort(trees.begin(), trees.end());
	
	int max_val = binary_search(0, trees[N-1], trees, M);
	cout << max_val << "\n";

	return 0;
}

int binary_search(int low, int high, vector<int>& trees, int M) {
	int result = 0;

	while (low <= high) {
		int mid = (low + high) / 2;

		long long sum = 0;
		for (int tree : trees) {
			if (tree > mid) sum += (tree - mid);
		}

		if (sum >= M) {
			result = mid;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return result;
}
