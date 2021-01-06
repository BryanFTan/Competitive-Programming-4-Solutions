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
    cin >> n;
    unordered_map<int, int> seating;
    int awk = n;
    int index = 1;
    while(n--) {
        int lang;
        cin >> lang;
        if (seating.count(lang)) {
            awk = min(awk, index - seating[lang]);
            seating[lang] = index;
        } else {
            seating[lang] = index;
        }
        index++;
    }
    cout << awk << "\n";

    return 0;
}