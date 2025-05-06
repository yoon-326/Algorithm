#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> A(12);

    A[0] = 1;
    A[1] = 1;
    A[2] = 2;
    A[3] = 4;

    while (n--) {
        int k;
        cin >> k;

        for (int i = 4; i <= k; i++) {
            A[i] = A[i - 1] + A[i - 2] + A[i - 3];
        }

        cout << A[k] << "\n";
    }

    return 0;
}