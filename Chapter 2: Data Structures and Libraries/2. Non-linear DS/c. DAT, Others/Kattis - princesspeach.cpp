//use bool array as DAT
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

    int N, Y;
    cin >> N >> Y;
    vector<bool> found(N, false);
    while(Y--) {
        int i;
        cin >> i;
        found[i] = true;
    }
    int count = 0;
    for (int i = 0; i < found.size(); i++) {
        if (found[i]) {
            count++;
        } else {
            cout << i << endl;
        }
    }
    printf("Mario got %d of the dangerous obstacles.", count);
    return 0;
}