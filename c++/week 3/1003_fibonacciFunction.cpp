#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<vector<int>> dp(41, (vector<int>(2)));

	dp[0][0] = 1; dp[0][1] = 0;
	dp[1][0] = 0; dp[1][1] = 1;

	for (int i = 2; i < 41; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
		dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
	}

	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		cout << dp[N][0] << " " << dp[N][1] << "\n";
	}

	return 0;
}