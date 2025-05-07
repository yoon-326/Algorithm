#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		unordered_map<string, int> clothes;
		int count = 1;

		for (int i = 0; i < n; i++) {
			string str, temp;
			cin >> temp >> str;

			clothes[str] += 1;
		}

		for (auto it = clothes.begin(); it != clothes.end(); it++) {
			count *= (it->second + 1);
		}

		cout << count - 1 << "\n";
	}

	return 0;
}