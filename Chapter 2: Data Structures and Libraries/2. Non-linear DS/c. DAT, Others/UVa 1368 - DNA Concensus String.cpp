/*
- search column by column for the most freq char
- anything else that is not the most freq char in the column, adds to the consensus error
- most freq chars of each column makes up the concensus string
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

    int T;
    cin >> T;
    while(T--) {
        int m, n;
        cin >> m >> n;
        char dna[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char c;
                cin >> c;
                dna[i][j] = c;
            }
        }
        //search column by column
        int error = 0;
        string s = "";
        for (int col = 0; col < n; col++) {
            int letters[26] = {0};
            char most_freq = '0';
            int freq = 0;
            for (int row = 0; row < m; row++) {
                letters[dna[row][col] - 'A']++;
                if (letters[dna[row][col] - 'A'] > freq) {
                    freq = letters[dna[row][col] - 'A'];
                    most_freq = dna[row][col];
                } else if (letters[dna[row][col] - 'A'] == freq) {
                    if (dna[row][col] < most_freq)
                        most_freq = dna[row][col];
                }
            }
            for (int row = 0; row < m; row++) {
                if (dna[row][col] != most_freq)
                    error++;
            }
            s += most_freq;
        }
        cout << s << "\n";
        cout << error << "\n";
    }

    return 0;
}