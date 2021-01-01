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

    int t, l, w, h;
    int c = 0;
    cin >> t;
    while(t--) {
        c++;
        cin >> l >> w >> h;
        if (l > 20 || w > 20 || h > 20) {
            printf("Case %d: bad\n", c);
        } else {
            printf("Case %d: good\n", c);
        }
    }

    return 0;
}