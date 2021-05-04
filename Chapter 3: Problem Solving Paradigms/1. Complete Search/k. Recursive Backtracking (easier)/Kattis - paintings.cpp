#include <bits/stdc++.h>

using namespace std;

#define IO                                  \
    freopen("../../../input.txt", "r", stdin); \
    freopen("../../../output.txt", "w", stdout);

void search(unordered_set<string> used, unordered_map<string, int>& colors, unordered_map<string, unordered_set<string>>& pairs, int& count, int score, vector<string>& favourite, vector<string> temp) {
    if (temp.size() == colors.size()) {
        count += 1;
        if (favourite.empty()) {
            favourite = temp;
        } else {
            bool found = false;
            for (int i = 0; i < temp.size(); i++) {
                if (colors[temp[i]] < colors[favourite[i]]) {
                    found = true;
                    break;
                } else if (colors[temp[i]] > colors[favourite[i]]) {
                    break;
                }
            }
            if (found) {
                favourite = temp;
            }
        }
        return;
    }

    for (auto it : colors) {
        string c = it.first;
        if (!used.count(c)) {
            if (temp.size() == 0 || (temp.size() > 0 && !pairs[c].count(temp[temp.size() - 1]))) {
                used.insert(c);
                temp.push_back(c);
                search(used, colors, pairs, count, score, favourite, temp);
                used.erase(c);
                temp.pop_back();
            }
        }
    }
}

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        unordered_map<string, int> colors;
        int idx = 0;
        while(N--) {
            string color;
            cin >> color;
            colors[color] = idx++;
        }

        int M;
        cin >> M;
        unordered_map<string, unordered_set<string>> pairs;
        while(M--) {
            string a, b;
            cin >> a >> b;
            pairs[a].insert(b);
            pairs[b].insert(a);
        }

        int count = 0;
        vector<string> favourite;
        unordered_set<string> used;
        search(used, colors, pairs, count, 0, favourite, {});
        cout << count << "\n";
        for (int i = 0; i < favourite.size(); i++) {
            cout << favourite[i];
            if (i < favourite.size() - 1) {
                cout << " ";
            } else {
                cout << "\n";
            }
        }
    }

    return 0;
}