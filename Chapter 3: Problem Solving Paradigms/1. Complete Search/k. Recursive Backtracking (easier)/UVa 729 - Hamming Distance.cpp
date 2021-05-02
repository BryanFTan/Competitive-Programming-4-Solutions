//do a complete search of all bit strings
//time: O(2^n)

#include <bits/stdc++.h>

using namespace std;

#define IO                                  \
    freopen("../../../input.txt", "r", stdin); \
    freopen("../../../output.txt", "w", stdout);

void getCombinations(string s, string builder, int H, int count, vector<string>& arr) {
    if (count > H) return;
    if (builder.size() == s.size()) {
        if (count == H) {
            arr.push_back(builder);
        }
        return;
    }

    getCombinations(s, builder + '0', H, count, arr);
    getCombinations(s, builder + '1', H, count + 1, arr);
}   

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int datasets;
    cin >> datasets;
    while(datasets--) {
        int N, H;
        cin >> N >> H;

        string s(N, '0');
        vector<string> arr;
        getCombinations(s, "", H, 0, arr);
        sort(arr.begin(), arr.end());
        for (auto& b : arr) {
            cout << b << "\n";
        }
        if (datasets > 0) cout << "\n";
    }

    return 0;
}