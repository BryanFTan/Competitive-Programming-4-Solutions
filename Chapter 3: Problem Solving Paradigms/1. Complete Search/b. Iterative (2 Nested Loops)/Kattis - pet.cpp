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

    int winner;
    int winning_score = 0;
    for (int i = 1; i <= 5; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int sum = a + b + c + d;
        if (sum > winning_score) {
            winner = i;
            winning_score = sum;
        }
    }
    cout << winner << " " << winning_score << "\n";

    return 0;
}