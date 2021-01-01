// Direct Addressing Table with first half uppercase, second half lowercase
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

    string s;
    while(getline(cin, s)) {
        vector<int> letters(51);
        for (char &c : s) {
            if (isalpha(c)) {
                if (islower(c)) {
                    letters[c - 'a' + 26]++;
                } else {
                    letters[c - 'A']++;
                }
            }
        }

        string alpha = "";
        int max = 0;
        for (int i = 0; i < letters.size(); i++) {
            int freq = letters[i];
            if (freq > max) {
                max = freq;
                alpha = "";
            } else if (freq < max) { 
                continue;
            }
            if (i > 25) {
                alpha += (char) ('a' + i - 26);
            } else {
                alpha += (char) ('A' + i);
            }
        }
        cout << alpha << " " << max << "\n";
    }

    return 0;
}