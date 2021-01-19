//check each permutation to find the minimum
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

    int R;
    cin >> R;
    vector<string> permutation;
    while(R--) {
        string s;
        cin >> s;
        permutation.push_back(s);
    }
    sort(permutation.begin(), permutation.end());
    int changes = INT_MAX;
    do {
        int count = 0;
        bool arr[26] = {false};
        
        for (char c : permutation[0]) {
            arr[c - 'A'] = true;
        }
        for (int i = 1; i < permutation.size(); i++) {
            for (char &c : permutation[i]) {
                if (arr[c - 'A']) count++;
            }
            for (int j = 0; j < 26; j++) arr[j] = false;
            for (char &c : permutation[i]) arr[c - 'A'] = true;
        }
        changes = min(changes, count);
    } while(next_permutation(permutation.begin(), permutation.end()));
    cout << changes << "\n";

    return 0;
}