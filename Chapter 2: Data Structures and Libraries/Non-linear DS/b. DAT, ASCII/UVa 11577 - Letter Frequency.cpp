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
    string line;
    cin >> n;
    getline(cin, line);
    while(n--) {
        vector<int> letters(26);
        getline(cin, line);
        for (char &c : line) {
            if (isalpha(c)) {
                c = tolower(c);
                letters[c - 'a']++;
            }
        }
        int freq = 0;
        string most_freq = "";
        for (int i = 0; i < 26; i++) {
            if (letters[i] > freq) {
                most_freq = "";
                most_freq += (char) 'a' + i;
                freq = letters[i];
            } else if (letters[i] == freq) {
                most_freq += (char) 'a' + i;
            }
        }
        cout << most_freq << "\n";
    }

    return 0;
}