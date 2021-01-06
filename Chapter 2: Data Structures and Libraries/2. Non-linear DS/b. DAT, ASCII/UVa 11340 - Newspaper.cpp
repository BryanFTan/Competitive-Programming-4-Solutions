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

    int N;
    cin >> N;
    while(N--) {
        int K, M;
        cin >> K;
        int values[K];
        string s;
        for (int i = 0; i < K; i++) {
            char c;
            int val;
            cin >> c >> val;
            s += c;
            values[i] = val;
        }
        cin >> M;
        string line;
        getline(cin, line);
        int cost = 0;
        while(M--) {
            getline(cin, line);
            for (auto &ch : line) {
                if (s.find(ch) != -1) {
                    cost += values[s.find(ch)];
                }
            }
        }
        double dollars = (double) cost / 100;
        cout << fixed << setprecision(2) << dollars;
        cout << "$" << "\n";
    }

    return 0;
}