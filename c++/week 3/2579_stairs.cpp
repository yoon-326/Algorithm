#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n; cin >> n;

	vector<int> dp(n);
	vector<int> val(n);
	
	for (int i = 0; i < n; i++) cin >> val[i];

	dp[0] = val[0];
	dp[1] = val[0] + val[1];
	dp[2] = val[2] + max(val[0], val[1]);

	for (int i = 3; i < n; i++) {
		dp[i] = val[i] + max(val[i - 1] + dp[i - 3], dp[i - 2]);
	}

	cout << dp[n - 1] << "\n";
	return 0;
}