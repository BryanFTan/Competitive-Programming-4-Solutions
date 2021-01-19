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
    int arr[6] = {0};
    for (int i = 1; i <= n; i++) {
        int die;
        cin >> die;
        die--;
        if (arr[die] == -1) continue;
        if (arr[die] == 0) {
            arr[die] = i;
        } else {
            arr[die] = -1;
        }
    }
    bool found = false;
    for (int i = 5; i >= 0; i--) {
        if (arr[i] != 0 && arr[i] != -1) {
            cout << arr[i] << "\n";
            found = true;
            break;
        }
    }
    if (!found) cout << "none" << "\n";

    return 0;
}