/*
- not complete search
- greedily take left reserved if not right, for each damaged 
*/
#include <bits/stdc++.h>

using namespace std;

#define IO                                  \
    freopen("../../../input.txt", "r", stdin); \
    freopen("../../../output.txt", "w", stdout);

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, S, R;
    cin >> N >> S >> R;
    set<int> damaged;
    unordered_set<int> reserved;

    while (S--) {
        int s;
        cin >> s;
        damaged.insert(s);
    }

    while(R--) {
        int r;
        cin >> r;
        reserved.insert(r);
    }
    vector<int> to_remove;
    for (auto it = damaged.begin(); it != damaged.end(); it++) {
        if (reserved.count(*it)) {
            reserved.erase(*it);
            to_remove.push_back(*it);
        }
    }
    for (auto i : to_remove) {
        damaged.erase(i);
    }

    for (auto it = damaged.begin(); it != damaged.end(); it++) {
        if (reserved.count(*it - 1)) {
            reserved.erase(*it - 1);
            to_remove.push_back(*it);
        } else if (reserved.count(*it + 1)) {
            reserved.erase(*it + 1);
            to_remove.push_back(*it);
        }
    }
    for (auto i : to_remove) {
        damaged.erase(i);
    }
    cout << damaged.size() << "\n";

    return 0;
}