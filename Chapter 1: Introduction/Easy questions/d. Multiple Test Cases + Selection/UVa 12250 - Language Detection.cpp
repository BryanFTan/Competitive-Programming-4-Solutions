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
    int count = 0;
    while(true) {
        cin >> s;
        if (s == "#") break;
        count++;
        if (s == "HELLO") {
            printf("Case %d: ENGLISH\n", count);
        } else if (s == "HOLA") {
            printf("Case %d: SPANISH\n", count);
        } else if (s == "HALLO") {
            printf("Case %d: GERMAN\n", count);
        } else if (s == "BONJOUR") {
            printf("Case %d: FRENCH\n", count);
        } else if (s == "CIAO") {
            printf("Case %d: ITALIAN\n", count);
        } else if (s == "ZDRAVSTVUJTE") {
            printf("Case %d: RUSSIAN\n", count);
        } else {
            printf("Case %d: UNKNOWN\n", count);
        }
    }

    return 0;
}