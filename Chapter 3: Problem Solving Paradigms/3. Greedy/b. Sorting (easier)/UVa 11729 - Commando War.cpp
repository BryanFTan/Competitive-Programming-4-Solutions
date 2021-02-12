/*
- breifings happen synchronously while jobs happen asynchronously
- all briefing timings will contribute to the completion time
- best to give the breifings whose jobs are the longest first 
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

    int N;
    int c = 0;
    while(cin >> N && N) {
        c++;
        vector<pair<int, int>> soldiers;
        while(N--) {
            int B, J;
            cin >> B >> J;
            soldiers.push_back({B, J});
        }
        sort(soldiers.begin(), soldiers.end(), [](pair<int, int> p1, pair<int, int> p2) {
            return p1.second > p2.second;
        });

        int breif_time = 0;
        int completion_time = 0;
        for (auto s : soldiers) {
            breif_time += s.first;
            completion_time = max(completion_time, breif_time + s.second);
        }
        printf("Case %d: %d\n", c, completion_time);
    }

    return 0;
}