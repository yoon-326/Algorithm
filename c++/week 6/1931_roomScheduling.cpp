#include <iostream>
#include <queue>

using namespace std;

struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.second == b.second) return a.first > b.first;
		return a.second > b.second;
	}
};

int main() {
	int n; cin >> n;

	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> schedule;

	for (int i = 0; i < n; i++) {
		int st, en; cin >> st >> en;
		schedule.push({ st, en });
	}

	int end_time = 0, total = 0;
	while (!schedule.empty()) {
		pair<int, int> select = schedule.top();
		if (end_time <= select.first) {
			total++;
			end_time = select.second;
		}
		schedule.pop();
	}

	cout << total << "\n";

	return 0;
}