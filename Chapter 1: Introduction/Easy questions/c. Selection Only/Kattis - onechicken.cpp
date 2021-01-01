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
    cin >> n >> m;

    if (n < m) {
        if (m - n > 1) {
            cout << "Dr. Chaz will have " << m - n << " pieces of chicken left over!" << "\n";
        } else {
            cout << "Dr. Chaz will have 1 piece of chicken left over!" << "\n";
        }
    } else {
        if (n - m > 1) {
            cout << "Dr. Chaz needs " << n - m << " more pieces of chicken!" << "\n";
        } else {
            cout << "Dr. Chaz needs 1 more piece of chicken!" << "\n";
        }
    }

    return 0;
}