//not really DAT
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

    string s;
    while(getline(cin, s)) {
        int prev = 0;
        int curr = 0;
        for (char &c : s) {
            if (c == 'B' || c == 'F' || c == 'P' || c == 'V') {
                curr = 1;
            } else if (c == 'D' || c == 'T') {
                curr = 3;
            } else if (c == 'L') {
                curr = 4;
            } else if (c == 'M' || c == 'N') {
                curr = 5;
            } else if (c == 'R') {
                curr = 6;
            } else if (c == 'C' || c == 'G' || c == 'J' || c == 'K' || c == 'Q' || c == 'S' || c == 'X' || c == 'Z') {
                curr = 2;
            } else {
                prev = 0;
                continue;
            }
            if (prev == curr) continue;
            prev = curr;
            cout << curr;
        }
        cout << "\n";
    }

    return 0;
}