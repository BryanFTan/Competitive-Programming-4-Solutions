#include <bits/stdc++.h>

using namespace std;

#define IO                            \
    freopen("../../../input.txt", "r", stdin); \
    freopen("../../../output.txt", "w", stdout);

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unordered_map<string, int> map;
    string s;
    getline(cin, s);
    int max = 0;
    bool tie = false;
    string name = "";
    while (s != "***") {
        map[s]++;
        if (map[s] > max) {
            max = map[s];
            tie = false;
            name = s;
        } else if (map[s] == max) {
            tie = true;
        }
        getline(cin, s);
    }
    if (tie) {
        cout << "Runoff!" << "\n";
    } else {
        cout << name << "\n";
    }

    return 0;
}