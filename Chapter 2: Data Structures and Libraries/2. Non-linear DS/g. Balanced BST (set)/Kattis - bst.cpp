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
    map<int, int> nodes;
    long long c = 0;
    while(n--) {
        int i;
        cin >> i;
        int depth = 0;
        auto it = nodes.lower_bound(i);
        if (it != nodes.end()) depth = max(depth, it->second + 1);
        if (it != nodes.begin()) depth = max(depth, (--it)->second + 1);
        nodes[i] = depth;
        c += depth;
        cout << c << "\n";
    }

    return 0;
}