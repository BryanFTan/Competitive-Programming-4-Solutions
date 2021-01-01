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
    stack<string> s;
    cin >> n;
    while(n--) {
        string cmd;
        cin >> cmd;
        if (cmd == "Sleep") {
            string name;
            cin >> name;
            s.push(name);
        } else if (cmd == "Kick") {
            if (s.size() > 0) {
                s.pop();
            }
        } else {
            if (s.size() > 0) {
                cout << s.top() <<"\n";
            } else {
                cout << "Not in a dream" <<"\n";
            }
        }
    }

    return 0;
}