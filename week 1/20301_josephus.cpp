#include <iostream>
#include <deque>

using namespace std;

deque<int> reversal(deque<int> permut);

int main() {
	int N, K, M;
	cin >> N >> K >> M;

	deque<int> permut;
	for (int i = 1; i <= N; i++) permut.push_back(i);

	int count = 1;
	int rm_count = 0;

	while (permut.empty() == 0 && K <= N && M <= N) {
		if (rm_count == M) {
			permut = reversal(permut);
			rm_count = 0;
		}

		if (count%K == 0) {
			cout << permut.front() << "\n";
			permut.pop_front();
			count++; rm_count++;
		}
		else {
			int temp = permut.front();
			permut.pop_front();
			permut.push_back(temp);
			count++;
		}
	}

	return 0;
}

deque<int> reversal(deque<int> permut) {
	deque<int> P;
	int size = permut.size();

	for (int i = 0; i < size; i++) {
		P.push_back(permut.back());
		permut.pop_back();
	}

	return P;
}