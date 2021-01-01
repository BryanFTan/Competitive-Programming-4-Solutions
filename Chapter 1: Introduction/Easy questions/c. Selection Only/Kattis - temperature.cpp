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

    int x, y;
    cin >> x >> y;
    if (x == 0 && y == 1) printf("ALL GOOD\n");
    else if (y == 1) printf("IMPOSSIBLE\n");
    else printf("%.6f\n", x / (1.0 - y));

    return 0;
}