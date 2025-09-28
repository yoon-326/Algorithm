#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T;
	cin >> T;

	vector<long long> P(101);
	P[0] = 0;
	P[1] = 1;
	P[2] = 1;
	P[3] = 1;
	P[4] = 2;
	P[5] = 2;
	P[6] = 3;
	P[7] = 4;
	P[8] = 5;

	for (int i = 9; i < 101; i++) {
		P[i] = P[i - 5] + P[i - 1];
	}

	while (T--) {
		int N; cin >> N;

		cout << P[N] << "\n";
	}
	return 0;
}