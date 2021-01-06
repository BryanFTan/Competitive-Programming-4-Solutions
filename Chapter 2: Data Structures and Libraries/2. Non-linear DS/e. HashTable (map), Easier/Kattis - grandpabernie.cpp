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
    unordered_map<string, vector<int>> map;
    while(n--) {
        string country;
        int year;
        cin >> country >> year;
        map[country].push_back(year);
    }

    for (auto it : map) {
        vector<int> v = it.second;
        sort(v.begin(), v.end());
        map[it.first] = v;
    }

    int q;
    cin >> q;
    while (q--) {
        int index;
        string country;
        cin >> country >> index;
        cout << map[country][index - 1] << "\n";
    }

    return 0;
}