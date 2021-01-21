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

    vector<pair<int, int>> recs;
    for (int i = 0; i < 3; i++) {
         int h, w;
         cin >> h >> w;
         recs.push_back({h, w});
    }
    vector<int> permutation = {0, 1, 2};
    bool valid = false;
    do {
        int h1, h2, h3, w1, w2, w3;
        for (int bit = 0; bit < (1 << 3); bit++) {
            h1 = bit & (1 << 0) ? recs[permutation[0]].first : recs[permutation[0]].second;
            w1 = bit & (1 << 0) ? recs[permutation[0]].second : recs[permutation[0]].first;
            h2 = bit & (1 << 1) ? recs[permutation[1]].first : recs[permutation[1]].second;
            w2 = bit & (1 << 1) ? recs[permutation[1]].second : recs[permutation[1]].first; 
            h3 = bit & (1 << 2) ? recs[permutation[2]].first : recs[permutation[2]].second;
            w3 = bit & (1 << 2) ? recs[permutation[2]].second : recs[permutation[2]].first; 
            //check 1.a
            if ((h1 + h2 + h3) == w1 && w1 == w2 && w2 == w3) {
                valid = true;
                break;
            }
            //check 1.b
            if ((h1 + h2) == w3 && w1 == w2 && (w1 + h3) == w3) {
                valid = true;
                break;
            }
        }
        if (valid) break;
    } while (next_permutation(permutation.begin(), permutation.end()));
    if (valid) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }

    return 0;
}