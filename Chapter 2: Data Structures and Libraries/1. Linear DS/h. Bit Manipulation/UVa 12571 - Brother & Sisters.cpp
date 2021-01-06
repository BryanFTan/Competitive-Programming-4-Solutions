/*
- Precalculate the max values for the range of a [0, 230]
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

    int T;
    cin >> T;
    while(T--) {
        int N, Q;
        cin >> N >> Q;
        vector<int> nums;
        for (int i = 0; i < N; i++) {
            int num;
            cin >> num;
            nums.push_back(num);
        }

        vector<int> pre;
        for (int i = 0; i < 230; i++) {
            int val = 0;
            for (int j = 0; j < N; j++) {
                val = max(val, (i & nums[j]));
            }
            pre.push_back(val);
        }

        while(Q--) {
            int a;
            cin >> a;
            cout << pre[a] << "\n";
        }
    }

    return 0;
}