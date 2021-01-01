//use parent-child mappings for complete binary tree
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

    int H;
    string seq;
    cin >> H >> seq;
    int index = 1;

    for (auto c : seq) {
        if (c == 'L') {
            index *= 2;
        } else {
            index = 2 * index + 1;
        }
    }
    H = pow(2, H + 1);
    cout << H - index << "\n";

    return 0;
}