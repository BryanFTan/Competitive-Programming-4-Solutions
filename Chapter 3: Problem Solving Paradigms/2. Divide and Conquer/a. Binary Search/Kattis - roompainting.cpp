#include <bits/stdc++.h>

using namespace std;

#define IO                                  \
    freopen("../../../input.txt", "r", stdin); \
    freopen("../../../output.txt", "w", stdout);

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> sizes(n);
    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        sizes[i] = s;
    }

    sort(sizes.begin(), sizes.end());

    long long count = 0;
    while(m--) {
        int num;
        cin >> num;
        int idx = lower_bound(sizes.begin(), sizes.end(), num) - sizes.begin();
        count += sizes[idx] - num;
    }

    cout << count << "\n";

    return 0;
}