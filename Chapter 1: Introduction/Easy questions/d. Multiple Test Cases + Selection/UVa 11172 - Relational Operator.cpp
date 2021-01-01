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

    int t, a, b;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        if (a < b) {
            cout << "<" << "\n";
        } else if (a == b) {
            cout << "=" << "\n";
        } else {
            cout << ">" << "\n";
        }
    }

    return 0;
}