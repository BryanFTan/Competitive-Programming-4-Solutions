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

    int n, m;
    while(cin >> n >> m) {
        unordered_map<int, vector<int>> map;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            map[x].push_back(i);
        }
        while(m--) {
            int k, v;
            cin >> k >> v;
            if (map[v].size() < k) {
                cout << 0 << "\n";
            } else {
                cout << map[v][k - 1] << "\n";
            }
        }
    }
    
    return 0;
}