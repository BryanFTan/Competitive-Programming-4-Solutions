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
    while(n--) {
        int M, W;
        cin >> M >> W;
        vector<int> ele(M);
        for (int i = 0; i < M; i++) {
            int w;
            cin >> w;
            ele[i] = w;
        }
        sort(ele.begin(), ele.end());
        long long sum = 0;
        int count = 0;
        for (int i = 0; i < M; i++) {
            if (sum + ele[i] > W) break;
            sum += ele[i];
            count++;
        }
        cout << count << "\n";
    }

    return 0;
}