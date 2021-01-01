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

    int l, r;
    cin >> l >> r;
    if (l == 0 && r == 0) {
        cout << "Not a moose" << "\n";
        return 0;
    }

    if (l == r) {
        cout << "Even" << " " << l + r << "\n";
    } else {
        if (l < r) l = r;
        cout << "Odd" << " " << 2 * l << "\n";
    }

    return 0;
}