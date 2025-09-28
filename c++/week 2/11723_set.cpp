#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int M, x;
    cin >> M;

    bool S[21] = { false };  // 1~20까지니까 인덱스 1~20 사용

    string cmd;

    while (M--) {
        cin >> cmd;

        if (cmd == "add") {
            cin >> x;
            S[x] = true;
        }
        else if (cmd == "remove") {
            cin >> x;
            S[x] = false;
        }
        else if (cmd == "check") {
            cin >> x;
            cout << (S[x] ? 1 : 0) << '\n';
        }
        else if (cmd == "toggle") {
            cin >> x;
            S[x] = !S[x];
        }
        else if (cmd == "all") {
            for (int i = 1; i <= 20; i++) S[i] = true;
        }
        else if (cmd == "empty") {
            for (int i = 1; i <= 20; i++) S[i] = false;
        }
    }

    return 0;
}