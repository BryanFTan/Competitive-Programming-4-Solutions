/*
- jobs with bigger fines and smaller days should be done first
- this is because you dont want to incur the big fines so you do them first
- and you dont want to delay other jobs so those with smallers days shld be done first
- hence, ratio of fine:days to be deciding factor
- sort by fine:days ratio in decreasing order
- if ratio is equal, sort by smaller index (lexicographically smaller)
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

    int c;
    cin >> c;
    while(c--) {
        int N;
        cin >> N;
        vector<tuple<int, int, int>> jobs(N);
        for (int i = 1; i <= N; i++) {
            int t, f;
            cin >> t >> f;
            jobs[i - 1] = make_tuple(i, t, f);
        }
        sort(jobs.begin(), jobs.end(), [](tuple<int, int, int> t1, tuple<int, int, int> t2){
            double ratio1 = (double) get<2>(t1) / get<1>(t1);
            double ratio2 = (double) get<2>(t2) / get<1>(t2);
            if (ratio1 == ratio2) {
                return get<0>(t1) < get<0>(t2);
            }
            return (double) get<2>(t1) / get<1>(t1) > (double) get<2>(t2) / get<1>(t2);
        });
        for (int i = 0; i < jobs.size(); i++) {
            if (i == jobs.size() - 1 && c != 0)  {
                cout << get<0>(jobs[i]) << "\n\n";
            } else if (i == jobs.size() - 1 && c == 0) {
                cout << get<0>(jobs[i]) << "\n";
            } else {
                cout << get<0>(jobs[i]) << " ";
            }
        }
    }

    return 0;
}