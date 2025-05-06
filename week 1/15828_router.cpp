#include <iostream>
#include <queue>

using namespace std;

int main() {
	long N;
	cin >> N;

	queue<int> router;

	int num;

	while (true) {
		cin >> num;

		if (num == -1) {
			if (router.empty() == 1) cout << "empty";
			while (router.empty() == 0) {
				cout << router.front() << " ";
				router.pop();
			}
			break;
		}

		if (num == 0) {
			if (router.empty() == 0) {
				router.pop();
				N++;
				continue;
			}
			else continue;
		}

		if (N != 0) {
			router.push(num);
			N--;
		}
	}

	return 0;
}