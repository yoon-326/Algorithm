#include <iostream>
#include <queue>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	queue<int> sql;

	for (int i = 1; i <= N; i++) {
		sql.push(i);
	}

	int last_sql;

	while (true) {
		if (sql.size() < K) {
			last_sql = sql.front();
			break;
		}

		int temp = sql.front();
		for (int i = 0; i < K; i++) {
			sql.pop();
		}
		sql.push(temp);
	}

	cout << last_sql;

	return 0;
}
