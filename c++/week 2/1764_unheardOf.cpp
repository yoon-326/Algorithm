#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    unordered_set<string> unheard;
    vector<string> result;


    string name;
    for (int i = 0; i < N; i++) {
        cin >> name;
        unheard.insert(name);
    }

    for (int i = 0; i < M; i++) {
        cin >> name;
        if (unheard.find(name) != unheard.end()) {
            result.push_back(name);
        }
    }

    sort(result.begin(), result.end());

    cout << result.size() << "\n";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << "\n";
    }

    return 0;
}