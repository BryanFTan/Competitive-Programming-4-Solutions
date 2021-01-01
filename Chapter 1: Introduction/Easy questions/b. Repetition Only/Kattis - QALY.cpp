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

    int n;
    double q, y, sum;
    sum = 0;
    cin >> n;
    while (n--) {
        cin >> q >> y;
        sum += q * y;
    }
    cout << sum << "\n";

    return 0;
}