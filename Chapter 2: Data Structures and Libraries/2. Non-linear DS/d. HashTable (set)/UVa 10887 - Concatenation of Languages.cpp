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
    int case_num = 1;
    while(T--) {
        int M, N;
        cin >> M >> N;
        string s;
        getline(cin, s);
        vector<string> m;
        while(M--) {
            getline(cin, s);
            if (!s.size()) {
                M++;
                continue;
            }
            m.push_back(s);
        }
        unordered_set<string> concat;
        while(N--) {
            getline(cin, s);
            if (!s.size()) {
                N++;
                continue;
            }
            for (string &st : m) {
                concat.insert(st + s);
            }
        }
        printf("Case %d: %d\n", case_num, concat.size());
        case_num++;
    }

    return 0;
}