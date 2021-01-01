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

    int g, s, c;
    cin >> g >> s >> c;
    int sum = g*3 + s*2 + c*1;

    if (sum >= 8) {
        cout << "Province or Gold" << "\n";
    } else if (sum >= 6) {
        cout << "Duchy or Gold" << "\n";
    } else if (sum >= 5) {
        cout << "Duchy or Silver" << "\n";
    } else if (sum >= 3) {
        cout << "Estate or Silver" << "\n";
    } else if (sum >= 2) {
        cout << "Estate or Copper" << "\n";
    } else {
        cout << "Copper" << "\n";
    }


    return 0;
}