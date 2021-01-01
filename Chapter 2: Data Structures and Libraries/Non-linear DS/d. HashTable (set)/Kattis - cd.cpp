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

    int N, M;
    cin >> N >> M;
    while(N != 0 && M != 0) {
        int num;
        int count = 0;
        unordered_set<int> set;
        for (int i = 0; i < N; i++) {
            cin >> num;
            set.insert(num);
        }
        for (int i = 0; i < M; i++) {
            cin >> num;
            if (set.count(num)) count++;
        }
        cout << count << "\n";
        cin >> N >> M;
    }
    return 0;
}