/*
- store up and down seperately and sort them
- Iterate through  each Height from H
    - check at that height how many obstacles are there
    - use left biased binary search to find obstacles for both up and down
    - maintain a mininum no. of obstacles
*/
#include <bits/stdc++.h>

using namespace std;

#define IO                                  \
    freopen("../../../input.txt", "r", stdin); \
    freopen("../../../output.txt", "w", stdout);

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, H;
    cin >> N >> H;
    vector<int> up(N/2);
    vector<int> down(N/2);
    int i = 0;
    while(N) {
        int u, d;
        cin >> u >> d;
        up[i] = u;
        down[i] = d;
        i++;
        N -= 2;
    }

    sort(up.begin(), up.end());
    sort(down.begin(), down.end());

    int minOb = up.size();
    int freq = 0;
    for (int i = 1; i <= H; i++) {
        int obs = 0;
        auto upIt = lower_bound(up.begin(), up.end(), i);
        if (upIt != up.end()) {
            obs += up.size() - (upIt - up.begin());
        }

        auto downIt = lower_bound(down.begin(), down.end(), H - i + 1);
        if (downIt != down.end()) {
            obs += down.size() - (downIt - down.begin());
        }

        if (obs < minOb) {
            minOb = obs;
            freq = 1;
        } else if (obs == minOb) {
            freq++;
        }
    }

    if (minOb == up.size() && freq == 0) {
        cout << 0 << " " << 0 << "\n";
    } else {
        cout << minOb << " " << freq << "\n";
    }

    return 0;
}