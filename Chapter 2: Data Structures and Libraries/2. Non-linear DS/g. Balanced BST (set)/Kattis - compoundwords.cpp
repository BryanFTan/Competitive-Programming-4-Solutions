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

    set<string> compounds;
    vector<string> words;
    string s;
    while(cin >> s) {
        for (string word : words) {
            compounds.insert(word + s);
            compounds.insert(s + word);
        }
        words.push_back(s);
    }
    for (auto it : compounds) {
        cout << it << "\n";
    }

    return 0;
}