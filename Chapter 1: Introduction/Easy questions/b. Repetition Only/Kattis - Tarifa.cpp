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
    
    int x, n, p, sum;
    sum = 0;
    cin >> x >> n;
    while (n--) {
        cin >> p;
        sum += x - p; 
    }
    cout << sum + x << "\n";

    return 0;
}