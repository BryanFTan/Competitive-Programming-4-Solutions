//classic interval covering algorithm
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
    while(n--) {
        int M, L, R;
        cin >> M;
        vector<pair<int, int>> intervals;
        while(cin >> L >> R) {
            if (L == 0 && R == 0) break;
            if (L >= M || R <= 0) continue; //skip those that dont even cover the segment
            intervals.push_back({L, R});
        }
        sort(intervals.begin(), intervals.end(), [](pair<int, int> a, pair<int, int> b){
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a.first < b.first;
        });
        int curr_end = 0;
        int count = 0;
        vector<pair<int, int>> ans;
        int possible = true;
        for (int i = 0; i < intervals.size(); i++) {
            if (!possible) break;
            if (curr_end >= M) break; //done
            auto p = intervals[i];
            if (p.second < curr_end) continue; //inside prev interval
            if (p.first <= curr_end) {
                int max_r = 0;
                int max_idx;
                int j = i;
                while(j < intervals.size() && intervals[j].first <= curr_end) {
                    if (intervals[j].second > max_r) {
                        max_r = intervals[j].second;
                        max_idx = j;
                    }
                    j++;
                }
                count++;
                curr_end = max_r;
                i = max_idx;
                ans.push_back(intervals[i]);
            } else if (p.first > curr_end) {
                possible = false;
            }
        }

        sort(ans.begin(), ans.end(), [](pair<int, int> a, pair<int, int> b){
            return a.first < b.first;
        });
        if (curr_end < M) {
            cout << 0 << "\n\n";
        } else {
            cout << count << "\n";
            for (auto p : ans) {
                cout << p.first << " " << p.second << "\n";
            }
            cout << "\n";
        }
    }

    return 0;
}