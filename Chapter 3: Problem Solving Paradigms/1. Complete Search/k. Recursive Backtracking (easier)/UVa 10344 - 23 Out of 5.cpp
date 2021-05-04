/*
- permute through all possible order of 5 digits
- for each order, try complete search of all operations
- time: O(5! * 3^4)
*/
#include <bits/stdc++.h>

using namespace std;

#define IO                                  \
    freopen("../../../input.txt", "r", stdin); \
    freopen("../../../output.txt", "w", stdout);

bool search(vector<int>& arr, int i, int val) {
    if (i == arr.size()) {
        return val == 23;
    }

    return search(arr, i + 1, val + arr[i]) 
        || search(arr, i + 1, val - arr[i]) 
        || search(arr, i + 1, val * arr[i]);
}

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, d, e;
    while(cin >> a >> b >> c >> d >> e) {
        if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0)
            break;

        vector<int> arr{a, b, c, d, e};

        sort(arr.begin(), arr.end());
        bool possible;
        do {
            possible = search(arr, 1, arr[0]);
            if (possible)
                break;
        } while (next_permutation(arr.begin(), arr.end()));

        string output = "";
        possible ? output = "Possible" : output = "Impossible";
        cout << output << "\n";
    }

    return 0;
}