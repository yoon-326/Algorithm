#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    string site, pwd;
    unordered_map<string, string> memo;

    for (int i = 0; i < N; i++) {
        cin >> site >> pwd;
        memo[site] = pwd;
    }

    for (int i = 0; i < M; i++) {
        string find;
        cin >> find;

        cout << memo[find] << "\n";
    }


    return 0;
}