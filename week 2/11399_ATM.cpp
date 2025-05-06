#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    sort(P.begin(), P.end());

    int sum = 0, result = 0;

    for (int i = 0; i < N; i++) {
        if (i == 0) {
            sum = P[i];
            result = P[i];
        }
        else {
            sum += P[i];
            result += sum;
        }
    }

    cout << result << "\n";

    return 0;
}