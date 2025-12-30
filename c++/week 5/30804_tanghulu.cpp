#include <iostream>
#include <queue>
#include <vector>
#include <numeric>

using namespace std;

void make_tanghulu(queue<int>& tanghulu, vector<int>& type);

int main() {
	int N; cin >> N;

	queue<int> tanghulu;
	vector<int> type(N+1, 0);
	while (N--) {
		int fruit; cin >> fruit;
		tanghulu.push(fruit);
		type[fruit]++;
	}
	make_tanghulu(tanghulu, type);

	return 0;
} 

void make_tanghulu(queue<int>& tanghulu, vector<int>& type) {
	int sum = accumulate(type.begin(), type.end(), 0);
	
}