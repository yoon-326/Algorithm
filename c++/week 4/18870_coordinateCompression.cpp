#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;

	vector<int> coordinate(n);
	vector<int> sorted;

	for (int i = 0; i < n; i++) {
		cin >> coordinate[i];
		sorted.push_back(coordinate[i]);
	}

	sort(sorted.begin(), sorted.end());
	sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

	map<int, int> val;
	for (int i = 0; i < sorted.size(); i++) {
		val[sorted[i]] = i;
	}

	for (int i = 0; i < n; i++) {
		cout << val[coordinate[i]] << " ";
	}
	cout << "\n";

	return 0;
}