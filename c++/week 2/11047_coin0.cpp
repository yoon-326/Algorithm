#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int result = 0;

    while (!A.empty()) {
        if (K == 0) break;

        if (A.back() > K) {
            A.pop_back();
        }
        else if (A.back() == K) {
            result += 1;
            break;
        }
        else {
            result += K / A.back();
            K = K % A.back();
            A.pop_back();
        }
    }

    cout << result << "\n";

    return 0;
}