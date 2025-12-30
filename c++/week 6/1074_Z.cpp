#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void visiting(int x, int y, int size, int row, int column, int& result);

int main() {
	int N, row, column; cin >> N >> row >> column;

	int result = 0;
	visiting(0, 0, pow(2, N), row, column, result);
	cout << result << "\n";

	return 0;
}

void visiting(int x, int y, int size, int row, int column, int& result) {
	if (size == 1) return;

	int val = pow(size / 2, 2);

    if (column < x + size / 2 && row < y + size / 2) {
        visiting(x, y, size / 2, row, column, result);
    }
    else if (column >= x + size / 2 && row < y + size / 2) {
        result += val;
        visiting(x + size / 2, y, size / 2, row, column, result);
    }
    else if (column < x + size / 2 && row >= y + size / 2) {
        result += val * 2;
        visiting(x, y + size / 2, size / 2, row, column, result);
    }
    else {
        result += val * 3;
        visiting(x + size / 2, y + size / 2, size / 2, row, column, result);
    }
}