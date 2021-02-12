/*
- Want to greedily buy goals for matches that can get the win the easiest
- Sort by smallest goal difference.
- Greedily buy to get a win by the minimum (1 goal)
*/
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

    int N, G;
    while(cin >> N >> G) {
        vector<pair<int, int>> scores;
        int points = 0;
        for (int i = 0; i < N; i++) {
            int S, R;
            cin >> S >> R;
            if (S > R) {
                points += 3;
            } else {
                scores.push_back({S, R});
            }
        }
        sort(scores.begin(), scores.end(), [](pair<int, int> &p1, pair<int, int> &p2) {
            return (p1.first - p1.second) > (p2.first - p2.second);
        });

        for (int i = 0; i < scores.size(); i++) {
            int diff = scores[i].second - scores[i].first + 1;
            if (G >= diff) {
                G -= diff;
                scores[i].first += diff;
            } else {
                scores[i].first += G;
                if (G > 0) G = 0;
            }
            if (scores[i].first > scores[i].second) {
                points += 3;
            } else if (scores[i].first == scores[i].second) {
                points += 1;
            }
        }
        cout << points << "\n";
    }

    return 0;
}