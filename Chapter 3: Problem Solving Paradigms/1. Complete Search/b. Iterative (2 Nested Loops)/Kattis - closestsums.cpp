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
    int c = 0;
    while (cin >> n) {
        c++;
        cout << "Case " << c << ":\n";
        vector<long long> arr;
        while (n--) {
            long long i;
            cin >> i;
            arr.push_back(i);
        }
        int m;
        cin >> m;
        while (m--) {
            long long j;
            cin >> j;
            long long diff = LLONG_MAX;
            long long closest;
            for (int a = 0; a < arr.size() - 1; a++) {
                for (int b = a + 1; b < arr.size(); b++) {
                    long long sum = arr[a] + arr[b];
                    if (llabs(j - sum) < diff) {
                        diff = llabs(j - sum);
                        closest = sum;
                    }
                }
            }
            cout << "Closest sum to " << j << " is " << closest << ".\n";
        }
    }

    return 0;
}