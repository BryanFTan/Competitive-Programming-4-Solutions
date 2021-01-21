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

    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> constraints;
    while(M--) {
        int a, b;
        cin >> a >> b;
        constraints.push_back({a - 1, b - 1});
    }
    int count = 0;
    for (int bit = 0; bit < (1 << N); bit++) {
        //check subset against contraints
        bool valid = true;
        for (auto &p : constraints) {
            //if a and b are set in bit
            if ((bit & (1 << p.first)) && (bit & (1 << p.second))) {
                valid = false;
                break;
            }
        }
        if (valid) count++;
    }
    cout << count << "\n";

    return 0;
}