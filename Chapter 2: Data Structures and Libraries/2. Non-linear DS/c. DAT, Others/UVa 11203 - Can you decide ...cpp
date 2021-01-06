/*
- didnt use DAT
- z = x + ?
- z + overflow = 1 + overflow
- middle = 1 + overflow
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
    cin >> N;
    while(N--) {
        string s;
        cin >> s;
        bool valid = true;
        if (s.find('M') == -1 || s.find('E') == -1 || s.find('?') == -1 || s[0] != '?') {
            cout << "no-theorem" << "\n";
            continue;
        }

        int x, y ,z;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c != '?' && c != 'M' && c != 'E') {
                valid = false;
                break;
            }
            if (c == 'M') x = i;
            if (c == 'E') {
                y = i - x - 1;
                z = s.size() - i - 1;
            } 
        }
        
        int overflow = z - x - 1;
        if (y != (1 + overflow) || y == 0) valid = false;
        if (!valid) {
            cout << "no-theorem" << "\n";
            continue;
        }
        cout << "theorem" << "\n";
    }


    return 0;
}