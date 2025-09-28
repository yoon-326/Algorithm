#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	string line;

	while (true) {
		getline(cin, line);
		if (line == ".") break;

		stack<char> balance;

		for (char x : line) {
			if (x == '(' || x == '[') balance.push(x);
			else if (x == ')' || x == ']') {
				if (balance.empty() != 1 && balance.top() == (x == ')' ? '(' : '[')) balance.pop();
				else {
					cout << "no\n";
					break;
				}
			}
			else if (x == '.') {
				if (balance.empty() == 1) cout << "yes\n";
				else {
					cout << "no\n";
					break;
				}
			}
		}
	}

	return 0;
}