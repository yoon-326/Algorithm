#include <iostream>
#include <sstream>
#include <string>

#define MAX_STACK_SIZE 10000
using namespace std;

int main() {
	int N;
	cin >> N;

	int stack[MAX_STACK_SIZE];
	int tp = -1;

	do {
		string line, word;
		int num;

		getline(cin, line);
		stringstream ss(line);

		ss >> word;


		if (word == "push") {
			ss >> num;
			stack[++tp] = num;
		}
		else if (word == "pop") {
			cout << ((tp == -1) ? -1 : stack[tp--]) << '\n';
		}
		else if (word == "size") {
			cout << tp + 1 << '\n';
		}
		else if (word == "empty") {
			cout << ((tp == -1) ? 1 : 0) << '\n';
		}
		else if (word == "top") {
			cout << ((tp == -1) ? -1 : stack[tp]) << '\n';
		}
	} while (N--);

	return 0;
}
