#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<string> list(N + 1);
    unordered_map<string, int> name_to_num;

    string name;
    for (int i = 1; i <= N; i++) {
        cin >> name;
        list[i] = name;
        name_to_num[name] = i;
    }

    while (M--) {
        string Q;
        cin >> Q;

        if (isdigit(Q[0])) {
            int num = stoi(Q);
            cout << list[num] << "\n";
        }
        else {
            cout << name_to_num[Q] << "\n";
        }
    }

    return 0;
}