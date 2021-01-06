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
    cin >> n;
    stack<int> s;

    for (int i = 0; i < n; i++) {
        int card;
        cin >> card;
        if (s.size() == 0 || (s.top() + card) % 2 != 0) {
            s.push(card);
        } else {
            s.pop();
        }
    }
    cout << s.size() << "\n";

    return 0;
}