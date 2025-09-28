#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> A(1001);

    A[0] = 1;
    A[1] = 1;

    for (int i = 2; i <= n; i++) {
        A[i] = (A[i - 1] + A[i - 2]) % 10007;
    }

    cout << A[n] << "\n";

    return 0;
}