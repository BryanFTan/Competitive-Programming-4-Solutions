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

    long long N;
    cin >> N;
    set<long long> seen;
    for (int i = 0; i <= sqrt(N); i++) {
        if (N % (i + 1) == 0) {
            seen.insert(i);
            seen.insert(N/(i + 1) - 1);
        }
    }
    set<long long>::iterator it;
    for (it = seen.begin(); it != seen.end(); it++) {
        if (++it == seen.end()) {
            it--;
            cout << *it << "\n";
        } else {
            it--;
            cout << *it << " ";
        }
    }

    return 0;
}