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
        int n, num_balls, sum, time;
        n = s.size();
        sum = 0;
        for (auto c : s) {
            sum += c - '0';
        }
        if (sum % n != 0) {
            printf("%s: invalid # of balls", s);
            break;
        }
        num_balls = sum / n;

        time = 1;
        
    }

    return 0;
}