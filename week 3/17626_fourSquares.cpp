#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;

	vector<int> dp(n + 1);
	vector<int> square;

	for (int i = 1; i * i <= n; i++) square.push_back(i * i);

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	dp[4] = 1;

	for (int i = 5; i <= n; i++) {
		int minval = INT_MAX;
		for (int j = 0; j < square.size() && square[j] <= i; j++) {
			if ((dp[i - square[j]] + 1) < minval) {
				minval = dp[i - square[j]] + 1;
			}
		}
		dp[i] = minval;
	}

	cout << dp[n] << "\n";

	return 0;
}