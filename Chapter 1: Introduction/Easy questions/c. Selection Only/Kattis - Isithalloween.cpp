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
    int i;
    cin >> s >> i;

    if ((s == "OCT" && i == 31) || (s == "DEC" && i == 25)) {
        cout << "yup" << "\n";
    } else {
        cout << "nope" << "\n";
    }

    return 0;
}