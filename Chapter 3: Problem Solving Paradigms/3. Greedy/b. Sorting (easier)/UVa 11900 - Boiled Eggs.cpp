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

    int T;
    int idx = 0;
    cin >> T;
    while (T--) {
        idx++;
        int n, P, Q;
        cin >> n >> P >> Q;
        vector<int> eggs(n);
        for (int i = 0; i < n; i++) {
            int g;
            cin >> g;
            eggs[i] = g;
        }
        sort(eggs.begin(), eggs.end());
        int count = 0;
        int weight = 0;
        int i = 0;
        for (int i = 0; i < n; i++) {
            if (count == P || weight + eggs[i] > Q) break;
            count++;
            weight += eggs[i];
        }
        printf("Case %d: %d\n", idx, count);
    }

    return 0;
}