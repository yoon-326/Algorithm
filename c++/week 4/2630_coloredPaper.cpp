#include <iostream>
#include <vector>

using namespace std;

void cutting(int x, int y, int size, vector<vector<int>>& P, int& white, int& blue);

int main() {
	int n;
	cin >> n;

	vector<vector<int>> P(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> P[i][j];
		}
	}

	int white = 0, blue = 0;
	cutting(0, 0, n, P, white, blue);

	cout << white << " " << blue << "\n";

	return 0;
}

void cutting(int x, int y, int size, vector<vector<int>>& P, int& white, int& blue) {
	if (size == 1) {
		if (P[x][y] == 0) white++;
		else blue++;
	}

	else {
		int val = P[x][y];
		bool correct = true;

		for (int i = x; i < x + size; i++) {
			for (int j = y; j < y + size; j++) {
				if (P[i][j] != val) {
					correct = false;
				}
			}
		}

		if (correct == true) {
			if (P[x][y] == 0) white++;
			else blue++;
		}
		else {
			int half = size / 2;
			cutting(x, y, half, P, white, blue);
			cutting(x + half, y, half, P, white, blue);
			cutting(x, y + half, half, P, white, blue);
			cutting(x + half, y + half, half, P, white, blue);
		}
	}
}