//iteratively generate all n, sort, upper_bound search
#include <bits/stdc++.h>

using namespace std;

#define IO                            \
    freopen("../../../input.txt", "r", stdin); \
    freopen("../../../output.txt", "w", stdout);

typedef long long ll;

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll m;
    while(true) {
        cin >> m;
        if (m == 0) break;
        vector<ll> nums;
        int i,j; 
        for(i = 0; i < 32; i++) {
            for(j = 0; j < 32; j++) {
                double p = pow(2,i)*pow(3,j);
                if(p <= m * 2) {
                    nums.push_back(p);
                }
            }
        }
        sort(nums.begin(), nums.end());
        auto it = upper_bound(nums.begin(), nums.end(), m);
        if (it != nums.begin() && nums[(it - 1) - nums.begin()] == m) {
            cout << m << "\n";
        } else {
            cout << nums[it - nums.begin()] << "\n";
        }
    }

    return 0;
} 