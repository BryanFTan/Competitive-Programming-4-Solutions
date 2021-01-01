/*
- iterate through all letters
- if letter cannot fit on-top any of the stacks (letter is bigger than tops), make a new stack for that letter
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

    string s;
    int c = 0;
    while (true) {
        cin >> s;
        if (s == "end") break;
        c++;
        vector<char> top;
        for (char ch : s) {
            bool didInsert = false;
            for (int i = 0; i < top.size(); i++) {
                if (ch <= top[i]) {
                    didInsert = true;
                    top[i] = ch;
                    break;
                }
            }
            if (!didInsert) {
                top.push_back(ch);
            }
        }
        printf("Case %d: %d\n", c, top.size());
        top.clear();
    }

    return 0;
}