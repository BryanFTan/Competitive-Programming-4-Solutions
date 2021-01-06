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

    int n, p, m;
    cin >> n >> p >> m;
    unordered_map<string, int> map;
    string name;
    while(n--) {
        cin >> name;
        map[name] = 0;
    }
    int winners = 0;
    while(m--) {
        int score;
        cin >> name >> score;
        if (map[name] >= p) continue;
        map[name] += score;
        if (map[name] >= p) {
            cout << name << " wins!" << "\n";
            winners++;
        }
    }
    if (!winners) {
        cout << "No winner!" << "\n";
    }

    return 0;
}