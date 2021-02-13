//nullify those with the biggest claims and smallest donations
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

    int T;
    cin >> T;
    int idx = 0;
    while (T--) {
        idx++;
        int N, K;
        cin >> N >> K;
        vector<pair<int, int>> biz(N);
        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            biz[i].first = x;
        }
        for (int i = 0; i < N; i++) {
            int y;
            cin >> y;
            biz[i].second = y;
        }
        sort(biz.begin(), biz.end(), [](pair<int, int> &p1, pair<int, int> &p2) {
            return (p1.first - p1.second) > (p2.first - p2.second);
        });
        long long profit = 0;
        for (int i = 0; i < N; i++) {
            if (K > 0 && biz[i].first > biz[i].second) {
                K--;
            } else {
                profit += biz[i].second - biz[i].first;
            }
        }
        cout << "Case " << idx << ": ";
        if (profit <= 0) {
            cout << "No Profit" << "\n";
        } else {
            cout << profit << "\n";
        }
    }

    return 0;
}