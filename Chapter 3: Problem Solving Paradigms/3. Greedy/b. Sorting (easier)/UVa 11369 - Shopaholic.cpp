//greedily take every 3rd item
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

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> items(n);
        for (int i = 0; i < n; i++) {
            int p;
            cin >> p;
            items[i] = p;
        }
        sort(items.rbegin(), items.rend());
        int counter = 0;
        int discount = 0;
        for (auto item : items) {
            counter++;
            if (counter == 3) {
                counter = 0;
                discount += item;
            }
        }
        cout << discount << "\n";
    }   

    return 0;
}